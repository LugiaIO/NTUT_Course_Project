class DialogflowModel():
    def __init__(self):
        self.eventName = None
        self.actionName = None
        self.queryInput = None
        self.parameters = {}
        self.responses = []
        self.lineId: None

 
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
        self.location_name = None
        self.price = None
        self.description = None
        self.web_sales = None

class ResponseModel():
    def __init__(self):
        self.status = -1
        self.result = None