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
        self.role = None

class ExModel():
    def __init__(self):
        self.id = None
        self.name = None
        self.time = None
        self.end_time = None
        self.location = None
        self.location_name = None
        self.price = None
        self.description = None
        self.web_sales = None

class ExRetrieveModel():
    def __init__(self):
        self.id = None
        self.name = None
        self.location = None

class StarRetrieveModel():
    def __init__(self):
        self.starid = None
        self.userid = None
        self.exid = None

class StarCreateModel():
    def __init__(self):
        self.userid = None
        self.exid = None

class UserCheckModel():
    def __init__(self):
        self.lineId = None