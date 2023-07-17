import os
from firebase_admin import credentials, firestore, initialize_app
import requests
import json
from model import UserModel,ExModel,StarModel,ResponseModel
import time
import uuid

# data model
user = UserModel()
ex = ExModel()
niubi = StarModel()
response = ResponseModel()

# firebase
cred = credentials.Certificate("firebaseKey.json")
initialize_app(cred)
db = firestore.client()

# firebase data collection
users_ref = db.collection("users")
exs_ref = db.collection("exhibition")
stars_ref = db.collection("stars")

def create(request):
    # 获取参数
    request_json = request.get_json()
    request_args = request.args

    # orderid
    starid = str(uuid.uuid1())
    niubi.id = starid

    # userid
    if request_json and "userid" in request_json:
        userid = request_json["userid"]
    elif request_args and "userid" in request_args:
        userid = request_args["userid"]
    else:
        userid = None

    # spotid
    if request_json and "exid" in request_json:
        exid = request_json["exid"]
    elif request_args and "exid" in request_args:
        exid = request_args["exid"]
    else:
        exid = None

    # debug
    # userid = "0123456789"
    # spotid = "1"
    # order.count = "2"

    niubi.datetime = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
    pass

    # 根据userid查找user
    if((userid != "")and(not userid is None)):
        user = users_ref.document(userid).get().to_dict()

        if(user != None):
            # 获取user
            niubi.user = user
        else:
            # 返回未找到
            response.status = "0"
            response.result = "未找到該用戶相關資料"
            return response.__dict__
    else:
        # 返回条件缺失
        response.status = "-1"
        response.result = "請輸入用戶"
        return response.__dict__

    # 根据spotid查找spot
    if((exid != "")and(not exid is None)):
        ex = exs_ref.document(exid).get().to_dict()

        if(ex != None):
            # 获取spot
            niubi.ex = ex
        else:
            # 返回未找到
            response.status = "0"
            response.result = "未找到該活動"
            return response.__dict__
    else:
        # 返回条件缺失
        response.status = "-1"
        response.result = "請輸入活動名稱"
        return response.__dict__

    # 新增订单
    stars_ref.document(starid).set(niubi.__dict__)
    response.status = "1"
    response.result = "創建推薦成功"
    print(response)
    return response.__dict__

# debug
# result = create("test")
# print(result)