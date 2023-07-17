import os
from firebase_admin import credentials, firestore, initialize_app
import requests
import json
from model import Ex,ExResponse

ex = Ex()
exResponse = ExResponse()

cred = credentials.Certificate('firebaseKey.json')
initialize_app(cred)
db = firestore.client()
exs_ref = db.collection('exhibition')


def retrieve(request):
    request_json = request.get_json()
    request_args = request.args

    # id
    if request_args and "id" in request_args:
        id = request_args["id"]
    elif request_json and "id" in request_json:
        id = request_json["id"]
    else:
        id = None

    # name
    if request_args and "name" in request_args:
        name = request_args["name"]
    elif request_json and "name" in request_json:
        name = request_json["name"]
    else:
        name = None

    # address
    if request_args and "location" in request_args:
        location = request_args["location"]
    elif request_json and "location" in request_json:
        location = request_json["location"]
    else:
        location = None
    
    if((id != "") and (not id is None)):
        exs = exs_ref.document(id).get().to_dict()
        result = []
        if(exs != None):
            result.append(exs)
            exResponse.status = "1"
            exResponse.result =result
        else:
            exResponse.status = "0"
            exResponse.result ="無相關資料"
    elif((name != "") and (not name is None)):
        exs = [exhibition.to_dict() for exhibition in exs_ref.stream()]
        result=[]
        for item in exs:
            if(name in item.get("name")):
                result.append(item)
        exResponse.status=len(result)
        exResponse.result=result
    elif((location != "") and (not location is None)):
        hama = [exhibition.to_dict() for exhibition in exs_ref.stream()]
        print (hama)
        result=[]
        for item in hama:
            if(location in str(item.get("location"))):
                result.append(item)
        exResponse.status=len(result)
        exResponse.result=result              
    else:
        # 返回错误
        exResponse.status = "-1"
        exResponse.result = "请输入查找条件"
    return exResponse.__dict__
