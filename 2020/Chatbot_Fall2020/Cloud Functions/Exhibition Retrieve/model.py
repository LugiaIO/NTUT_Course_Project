class Ex():
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

class ExResponse():
    def __init__(self, status=None, result=None):
        self.status = status
        self.result = result
