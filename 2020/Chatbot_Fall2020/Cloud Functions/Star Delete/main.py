import os
from firebase_admin import credentials, firestore, initialize_app
from model import StarModel, ResponseModel

starModel = StarModel()
responseModel = ResponseModel()

cred = credentials.Certificate('firebaseKey.json')
initialize_app(cred)
db = firestore.client()
users_ref = db.collection('users')
exs_ref = db.collection('exhibition')
stars_ref = db.collection('stars')

def delete(request):
    request_json = request.get_json()
    id = request_json['id']

    responseModel.result = {}

    star = stars_ref.document(id).get().to_dict()

    if(star == None):
        responseModel.status = -1
    else:
        stars_ref.document(id).delete()
        responseModel.status = 1

    return responseModel.__dict__

