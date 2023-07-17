from sgml_parser.parser import parser
from text_classifier import running

if __name__ == "__main__":
    print("********** Start Parsing **********")
    text_parm = parser()
   # print(type(text_parm[0]))
    print("********** Start Classifying **********")
    running.tcrun(text_parm[0], text_parm[1], text_parm[2], text_parm[3])
