import os
from firebase_admin import credentials, firestore, initialize_app
import requests
import json
from model import StarModel,ResponseModel

# data model
star = StarModel()
response = ResponseModel()

# firebase
cred = credentials.Certificate("firebaseKey.json")
initialize_app(cred)
db = firestore.client()

# firebase data collection
stars_ref = db.collection("stars")

def retrieve(request):
    # # debug
    # orderid = ""
    # userid = ""
    # spotid = "5374"

    # 获取参数
    request_json = request.get_json()
    request_args = request.args

    # orderid
    if request_json and "starid" in request_json:
        starid = request_json["starid"]
    elif request_args and "starid" in request_args:
        starid = request_args["starid"]
    else:
        starid = ""

    # userid
    if request_json and "userid" in request_json:
        userid = request_json["userid"]
    elif request_args and "userid" in request_args:
        userid = request_args["userid"]
    else:
        userid = ""

    # spotid
    if request_json and "exid" in request_json:
        exid = request_json["exid"]
    elif request_args and "exid" in request_args:
        exid = request_args["exid"]
    else:
        exid = ""

    if(starid != ""):
        # 根据订单id查找
        star = stars_ref.document(starid).get().to_dict()

        if(star != None):
            # 返回结果
            response.status = "1"
            response.result = star
        else:
            # 返回未找到
            response.status = "0"
            response.result = "未找到相關資料"

    elif(userid != ""):
        # 根据用户id查找

        # 取出所有
        stars = [star.to_dict() for star in stars_ref.stream()]
        result = []

        # 根据用户id查找
        for item in stars:
            if(userid == item.get("user").get("phone")):
                result.append(item)

        # 返回结果条数和结果
        response.status = len(result)
        response.result = result

    elif(exid != ""):
        # 根据景点id查找:

        # 取出所有
        stars = [star.to_dict() for star in stars_ref.stream()]
        result = []

        # 根据景点id查找
        for item in stars:
            if(spotid == item.get("ex").get("id")):
                result.append(item)

        # 返回结果条数和结果
        response.status = len(result)
        response.result = result

    else:
        response.status = "1"
        response.result = [star.to_dict() for star in stars_ref.stream()]

    # 返回结果
    print("response: " + str(response.status))
    return response.__dict__

# # 测试request
# retrieve("test")