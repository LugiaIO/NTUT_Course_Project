class ResponseModel():
    def __init__(self):
        self.status = -1
        self.result = None

class UserModel():
    def __init__(self):
        self.name = None
        self.phone = None
        self.email = None
        self.lineId = None
        self.role = "customer"

class ExModel():
    def __init__(self):
        self.id = None
        self.name = None
        self.time = None
        self.end_time = None
        self.location = None
        

class StarRequestMode():
    def __init__(self):
        self.userid = None
        self.exid = None
        self.star = None

class StarModel():
    def __init__(self):
        self.id = None
        self.user = None
        self.ex = None
        self.datetime = None