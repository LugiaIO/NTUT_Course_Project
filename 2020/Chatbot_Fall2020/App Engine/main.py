import os
from functools import wraps
from flask import Flask, request, render_template,session,redirect,url_for
import requests
import json
from model import UserModel,ExModel,StarModel
import exsConfig

app = Flask(__name__,
            static_url_path='', 
            static_folder='static',
            template_folder='templates')
app.secret_key = 'A0Zr98j/3yX R~XHH!jmN]LWX/,?RT'

userModel = UserModel()
exModel= ExModel()
starModel = StarModel()
@app.route("/exs/index", methods=['GET'])
def index():
    global userModel,exModel
    try:
        userModel.lineId = request.values['lineId']
    except:
        pass
    return render_template("index.html", userModel=userModel)


@app.route('/exs/list', methods=['GET', 'POST'])
def list():
    apiResponse = requests.get(exsConfig.listApi)

    starResponse = apiResponse.json()
    starLength = len(starResponse['result'])

    return render_template('listStarResponse.html', starModel=starResponse, length=starLength)

@app.route('/exs/query', methods=['GET'])
def query():
    return render_template("queryExRequest.html")

@app.route('/exs/queryResult', methods=['GET', 'POST'])
def queryR():
    #global userModel
    if request.method == "GET":
        #return render_template("queryExRequest.html")
        type=request.values['type']
        parm=request.values['parm']
        apiResponse = requests.get(exsConfig.queryApi+'?'+type+'='+parm)
        exResponse = apiResponse.json()
        exLength = len(exResponse['result'])
        if exLength>0:
            return render_template('queryExResponse.html', exModel=exResponse,length=exLength)
        else:
            return render_template('queryExFail.html', exModel=exResponse)

@app.route('/exs/admin', methods=['GET', 'POST'])
def admin():
    #global userModel
    if request.method == "GET":
        return render_template("login.html")
    else:
        email = request.values['email']
        password = request.values['password']
        if email == "tiansuo@gmail.com" and password =="114514":
            session['user_id'] = 114514
            return redirect((url_for('deleteList')))
        else:
            return redirect((url_for('admin')))

def is_login(func):
    @wraps(func)
    def check_login(*args, **kwargs):
        if 'user_id' in session:
            return func(*args, **kwargs)
        else:
            return redirect(url_for('admin'))
    return check_login

@app.route('/exs/panel', methods=['GET', 'POST'])
@is_login
def deleteList():
    apiResponse = requests.get(exsConfig.listApi)
    starResponse = apiResponse.json()
    starLength = len(starResponse['result'])

    return render_template('deleteRequest.html', starModel=starResponse, length=starLength)

@app.route('/exs/delete', methods=['GET'])
def delete():
    if request.method == "GET":
        starModel = StarModel(id=request.values['id'])
        starResponse = requests.delete(
            exsConfig.deleteApi, json=starModel.__dict__)

        starResponse = starResponse.json()

        if str(starResponse['status']) == "1":
            return render_template("deleteResponse.html")
        else:
            return render_template("deleteFail.html")

@app.route('/exs/logout', methods=['GET'])
def logout():
    session.pop('user_id', None)
    return redirect(url_for('index'))

