# Newsline folder and format
import re
import xml.sax.saxutils as saxutils
from bs4 import BeautifulSoup

data_folder = './data/'
sgml_number_of_files = 22
sgml_file_name_template = 'reut2-NNN.sgm'

def strip_tags(text):
    return re.sub('<[^<]+?>', '', text).strip()

def unescape(text):
    return saxutils.unescape(text)

def parser():
    document_train = {}
    document_test = {}
    document_label = {}
    documents = []
    for i in range(sgml_number_of_files):
        if i < 10:
            seq = '00' + str(i)
        else:
            seq = '0' + str(i)

        file_name = sgml_file_name_template.replace('NNN', seq)
        print('Reading file: %s' % file_name)

        with open(data_folder + file_name, 'r', encoding='windows-1252') as file:
            content = BeautifulSoup(file.read().lower(), 'lxml')
            for newsline in content('reuters'):
                if (newsline['lewissplit'] == 'train' and newsline['topics'] == 'yes'):
                    for label in newsline('topics'):
                        document_categories = []
                        #print (label)
                        if(label.text != '<topics></topics>'):
                            for d in label('d'):
                                document_categories.append(d.text)
                                document_label["training/" +
                                               newsline['newid']] = document_categories
                                documents.append("training/"+newsline['newid'])
                    document_id = newsline['newid']
                    document_body = strip_tags(str(newsline('text')[0].text)).replace(
                        'reuter\n&#3;', '').replace('reuter', '')
                    document_body = unescape(document_body)
                    document_train["training/"+document_id] = document_body
                elif (newsline['lewissplit'] == 'test' and newsline['topics'] == 'yes'):
                    for label in newsline('topics'):
                        document_categories = []
                        if(label.text != '<topics></topics>'):
                            for d in label('d'):
                                document_categories.append(d.text)
                                document_label["test/"+newsline['newid']
                                               ] = document_categories
                                documents.append("test/"+newsline['newid'])
                    document_id = newsline['newid']
                    document_body = strip_tags(str(newsline('text')[0].text)).replace(
                        'reuter\n&#3;', '').replace('reuter', '')
                    document_body = unescape(document_body)
                    document_test["test/"+document_id] = document_body
    return document_train, document_test, document_label, documents
