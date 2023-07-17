import json
import model
import requests
import dialogflowClient
from chatBotConfig import channel_secret, channel_access_token
from linebot import WebhookHandler, LineBotApi
from linebot.exceptions import InvalidSignatureError
from linebot.models import FollowEvent, TextSendMessage, MessageEvent, TextMessage
from umsConfig import umsWebApi
from exConfig import exApi, userApi,starApi
import myModel

handler = WebhookHandler(channel_secret)
linebotApi = LineBotApi(channel_access_token)
dialogflowModel = model.DialogflowModel()
userModel = model.UserModel()


# (1) functions
def model_init_(lineId):
    global dialogflowModel, userModel
    dialogflowModel = model.DialogflowModel()
    userModel = model.UserModel()
    dialogflowModel.lineId = userModel.lineId = lineId


def actionDispatch():
    url = umsWebApi + dialogflowModel.actionName
    
    if (dialogflowModel.actionName in ['create', 'delete', 'update']):
        result = requests.post(url, json=userModel.__dict__)
        
    elif (dialogflowModel.actionName == 'retrieve'):
        result = requests.get(url + '?phone=' + userModel.phone)

    return result

# custom function call web api
def callWebApi(actionName,request_input):
    # 根据action不同，传入参数不同，调用不同的web api
    if ("queryEx_" in actionName):
        # spotId
        url = exApi
        json_request = request_input.__dict__
        if (request_input.name!=None):
            result = requests.get(url+'?name='+request_input.name)
        elif (request_input.location!=None):
            print (request_input.location)
            result = requests.get(url+'?location='+str(request_input.location))
    elif(actionName == "checkUser"):
        # check user
        url = userApi + "check"
        json_request = request_input.__dict__
        result = requests.post(url,json=json_request) 
    elif(actionName == "starList"):
        # book ticket
        url = starApi + "create"
        print (request_input)
        json_request = request_input.__dict__
        print (json_request)
        result = requests.post(url,json=json_request)

    else:
        Exception()

    return result



def replyMessageToUser(replyToken, texts):
    replyMessages = []
    for text in texts:
        replyMessages.append(TextSendMessage(text=text))
    linebotApi.reply_message(replyToken, replyMessages)


# (2) Webhook
#@app.route("/webhook",methods=['GET', 'POST'])
def lineWebhook(request):
#def lineWebhook():
    # get X-Line-Signature header value
    signature = request.headers.get('X-Line-Signature')

    # get request body as text
    body = request.get_data(as_text=True)

    # handle webhook body
    try:
        handler.handle(body, signature)
    except InvalidSignatureError:
        abort(400)

    return '200 OK'


# (3) Follow Event
@handler.add(FollowEvent)
def handle_follow(event):
    model_init_(event.source.user_id)
    dialogflowModel.lineId = event.source.user_id
    dialogflowModel.eventName = 'welcomeEvent'
    dialogflowClient.eventDispatch(dialogflowModel)
    replyMessageToUser(event.reply_token, dialogflowModel.responses)


# (4) Message Event
@handler.add(MessageEvent, message=TextMessage)
def handle_message(event):
    model_init_(event.source.user_id)
    dialogflowModel.queryInput = event.message.text
    dialogflowClient.queryDispatch(dialogflowModel)
    
    if (dialogflowModel.actionName):
        
        # hack custom code
        # 调用callWebApi呼叫自定义api
        # 用event.reply_token和dialogflowModel.responses直接调用replyMessageToUser
        flag=""
        actionName = dialogflowModel.actionName
        response = myModel.ResponseModel()
        response_text = ""
        texts = []
        if ("queryEx_" in dialogflowModel.actionName):
            #查询类
            exRetrieveModel = myModel.ExRetrieveModel() 

            if (actionName == "queryEx_name"):
                # 通过名称查询
                exRetrieveModel.name = dialogflowModel.parameters["exName"] 
                flag="name"

            elif (actionName == "queryEx_location"):
                # 通过地址查询
                exRetrieveModel.location = dialogflowModel.parameters["exLocation"]
                flag="location"
            else:
                print("No method handle:" + actionName)
                pass

            # call web api
            result = callWebApi(actionName,exRetrieveModel)
            response.__dict__ = json.loads(result.text)
            count = int(response.status)
            
            if(count > 1):
                # 查询到多条结果，显示前N个，
                limit = 5 if count > 5 else count
                exs = response.result[:limit]
                response_text += "讓您久等了，指北君為您查詢到 {n} 個活動，篇幅原因顯示前 {l} 個：\n\n".format(n=str(count),l=str(limit))
                if exRetrieveModel.location != None:
                    response_text +="想查詢全部活動的話，去 https://chatbot-108aea001-296006.appspot.com/exs/queryResult?type=location&parm="+exRetrieveModel.location+"\n\n"
                elif exRetrieveModel.name != None:
                    response_text +="想查詢全部活動的話，去 https://chatbot-108aea001-296006.appspot.com/exs/queryResult?type=name&parm="+exRetrieveModel.name+"\n\n"
                for item in exs:
                    ex = myModel.ExModel()
                    ex.__dict__ = item
                    response_text += "活動序號：{id}\n活動名稱：{name}\n開始時間：{time}\n結束時間：{end_time}\n活動地址：{location}\n\n".format(id=ex.id,name=ex.name,time=ex.time,end_time=ex.end_time,location=ex.location)
                pass


            elif(count == 1):
                ex = myModel.ExModel()
                ex.__dict__ = response.result[0]

                response_text += "麻煩讓您久等了喔，這個活動的詳情如下：\n"
                response_text += "\n"   
                response_text += "活動序號：{}\n".format(ex.id)
                response_text += "活動名稱：{}\n".format(ex.name)
                response_text += "開始時間：{}\n".format(ex.time)
                response_text += "結束時間：{}\n".format(ex.end_time)
                response_text += "活動地址：{}\n".format(ex.location)
                response_text += "場地名稱：{}\n".format(ex.location_name)
                response_text += "簡介說明：{}\n".format(ex.description)
                response_text += "售票說明：{}\n".format(ex.price)
                response_text += "售票網站：{}\n".format(ex.web_sales)
                pass

            elif(count == 0):
                response_text += "很抱歉呢，指北君沒有找到相關活动。"
                pass

            else:
                response_text += "錯誤：\n"
                pass
                # 查询出错
            
            texts.append(response_text)
            replyMessageToUser(event.reply_token,texts)
            return
        elif (actionName == "starList"):
            # 订票
            # 查询用户是否注册
            actionName = "checkUser"
            userCheck = myModel.UserCheckModel()
            userCheck.lineId = dialogflowModel.lineId
            result = callWebApi(actionName,userCheck)

            response.__dict__ = json.loads(result.text)
            count = int(response.status)

            if(count == 1):
                # 用户已注册
                actionName = "starList"
                user = myModel.UserModel()
                user.__dict__ = response.result
                # 创建订票请求
                starCreateModel = myModel.StarCreateModel()
                starCreateModel.userid = user.phone
                starCreateModel.exid = str(dialogflowModel.parameters["exid"])
                # 订票
                result = callWebApi(actionName,starCreateModel)
                response.__dict__ = json.loads(result.text)
                status = int(response.status)

                if(status == 1):
                    # 訂票成功
                    response_text += "推薦活動成功！"
                else:
                    # 訂票失敗
                    response_text += "推薦活動失敗：\n"
                    response_text += str(response.result)

            else:
                # 用户未注册
                response_text += "請先注冊用戶喔～"

            texts.append(response_text)
            replyMessageToUser(event.reply_token,texts)
            return        
        else:
            # 原代码
            if (dialogflowModel.actionName == 'update'):
                dialogflowModel.actionName = 'retrieve'
                userModel.phone = dialogflowModel.parameters['phone']
                result = actionDispatch()
                originalUserData = json.loads(result.text)['userModel']
                newUserData = json.loads(result.text)['userModel']
                
                for key in dialogflowModel.parameters:
                    newUserData[key] = dialogflowModel.parameters[key]
                    
                dialogflowModel.parameters = newUserData
                dialogflowModel.actionName = 'update'
            
            for key in dialogflowModel.parameters:
                setattr(userModel, key, dialogflowModel.parameters[key])
                
            result = actionDispatch()
            
            if (json.loads(result.text)['result']['code'] == '1'):
                dialogflowModel.parameters = json.loads(result.text)['userModel']
                dialogflowModel.eventName = dialogflowModel.actionName + '_responseEvent'  
                
            else:
                dialogflowModel.eventName = dialogflowModel.actionName + '_failResponseEvent'
                
            if (dialogflowModel.actionName == 'update'):
                dialogflowModel.parameters = originalUserData

            dialogflowClient.eventDispatch(dialogflowModel)

    replyMessageToUser(event.reply_token, dialogflowModel.responses)