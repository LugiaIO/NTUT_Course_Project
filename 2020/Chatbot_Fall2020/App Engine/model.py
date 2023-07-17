class UserModel():
    def __init__(self, name=None, phone=None, email=None, role=None, lineId=None):
        self.name = name
        self.phone = phone
        self.email = email
        self.role = "customer"
        self.lineId = "Uedef6a810f69246dc30b3c15afdcb2f4"


class UserResponse():
    def __init__(self, userModel=None, result=None):
        self.userModel = userModel
        self.result = result


class ExResponse():
    def __init__(self, exModel=None, status=None):
        self.exModel = exModel
        self.status = status

class ExModel():
    def __init__(self, id=None, name=None, time=None, end_time=None, location=None, location_name=None, price=None, description=None, web_sales=None):
        self.id = id
        self.name = name
        self.time = time
        self.end_time = end_time
        self.location = location
        self.location_name = location_name
        self.price = price
        self.description = description
        self.web_sales = web_sales

class StarModel():
    def __init__(self, id=None, exModel=None, userModel=None):
        self.id = id
        self.exModel = exModel
        self.userModel = userModel

