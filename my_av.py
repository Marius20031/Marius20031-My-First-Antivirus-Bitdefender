#!/usr/bin/python3
##print("hello")

############----------TASK1----------#
def verifbaza(buffer,semafor):
    finame="data/urls/domains_database"
    finale= open(finame,"r")

    vector=finale.read()
    vector=vector.split()
    buffer=buffer.split('/')
  #print(buffer[0])
  #print(buffer)
    for vectoras in vector:
        if vectoras==buffer[0]:
            semafor.insert(0,1)
      #print(vectoras)
    finale.close()

def verifbazaToshiro(buffer,semafor):
    finame="Toshiro_db.txt"
    finale= open(finame,"r")

    vector=finale.read()
    vector=vector.split()
    buffer=buffer.split('/')
  #print(buffer[0])
    #print("mere")
    for vectoras in vector:
        if vectoras in buffer[0]:
            #print("mere")
            semafor.insert(0,1)
      #print(vectoras)
    finale.close()

def verifbazaSUM(buffer,semafor):
    finame="SUM.txt"
    finale= open(finame,"r")

    vector=finale.read()
    vector=vector.split()
    buffer=buffer.split('/')
  #print(buffer[0])
    #print("mere")
    for vectoras in vector:
        if vectoras in buffer[0]:
            #print("mere")
            semafor.insert(0,0)
      #print(vectoras)
    finale.close()

def verifterminator(buffer,semafor):

    aux=buffer
    aux=aux.split('/')

    mere=buffer
    mere=mere.split('/')

    if mere[0]==buffer:
      semafor.insert(0,1)
    #if aux[0] in buffer:
      #semafor.insert(0,1)
    for vectoras in aux:
        for caracter in vectoras:
            if caracter.isdigit()==1: # daca are cifre ca domeniu
                semafor.insert(0,1)
        #if "facebook" in vectoras and vectoras!="facebook.com":
          #semafor.insert(0,1)
        #if "paypal" in vectoras and vectoras!="paypal.com":
          #semafor.insert(0,1)
        break
      #print(vectoras)
    if buffer.endswith(".exe"):
        semafor.insert(0,1)
    if buffer.endswith(".i"):
        semafor.insert(0,1)
    if buffer.endswith(".bin"):
        semafor.insert(0,1)
    if buffer.endswith(".pdf"):
        semafor.insert(0,1)
    if buffer.endswith("Mozi.m"):
        semafor.insert(0,1)
    if buffer.endswith(".doc"):
        semafor.insert(0,1)
    if buffer.endswith(".css"):
        semafor.insert(0,1)
    if buffer.endswith(".js"):
        semafor.insert(0,1)
    if buffer.endswith(".arm"):
        semafor.insert(0,1)
    if buffer.endswith(".htm"):
        semafor.insert(0,1)

    if "=com" in buffer:
      semafor.insert(0,1)
    if "mod_" in buffer:
      semafor.insert(0,1)
    if "login" in buffer:
      semafor.insert(0,1)
    if "com." in buffer:
      semafor.insert(0,1)
    if "/exe/" in buffer:
      semafor.insert(0,1)
    if "html" in buffer:
      semafor.insert(0,0)
    if "'" in buffer:
      semafor.insert(0,0)
  #print("mere")

def veriftopleveldoiam(buffer,semafor):
  #gasim top level domain si egalam cu alea cunoscute
  #documentatie get_tld
  #res = get_fld(buffer, fail_silently=True)
  #print(res)
  buffer=buffer.split('/')

  finamein="Yggdmillennia.txt"
  finale= open(finamein,"r")

  vector=finale.read()
  reading=vector.split()

  File1="SoulSociety.txt"
  Soul= open(File1,"r")

  vector1=Soul.read()
  reading1=vector1.split()

  for domain in reading:
    for tari in reading1:
      print(domain+tari)
      #if(buffer[0].endswith(line+tari)):
       #semafor.insert(0,0)

    #print(semafor[0], file=fonale)
    #break
  finale.close()


def soltask1(buffer,semafor):
  #print(buffer)
  #recunoastem daca are la finalenal .exe sau cv
  #verifinalecam daca e in baza de date
  #semafor =[0];
    verifterminator(buffer,semafor)
    verifbaza(buffer,semafor)
    verifbazaToshiro(buffer,semafor)
    verifbazaSUM(buffer,semafor)
    #veriftopleveldoiam(buffer,semafor)
  #semafor = semafor;
  #semafor.insert(0,semafor[0]) # !!!!!!!!!

def task1():
    finamein="data/urls/urls.in"
    finameout="urls-predictions.out"
    finale= open(finamein,"r")
    fonale= open(finameout,"w")
    vector=finale.read()
    reading=vector.split()
    for line in reading:
        semafor=[0]
        soltask1(line,semafor)
        print(semafor[0], file=fonale)
    #break
    finale.close()
    fonale.close()




#################---------TASK2-------#
def verifflowdurat(buffer,semafor):
    aux=buffer
    aux=aux.split(',')
    nr=0
    #print(aux)
    #print(aux[2])
    #safe: 3306 50443 1515
    #malitios: 443 1947 137


    if aux[3]=="443":
     semafor.insert(0,1)
    if aux[3]=="1947":
      semafor.insert(0,1)
    if aux[3]=="137":
      semafor.insert(0,1)

    #if aux[3]!="137" and aux[3]!="1947":
        #if aux[3]!="443" and aux[3]!="1515":
          #if aux[3]!="50443" and aux[3]!="3306":
            #print(aux[3])
    if aux[2]=="184.0.48.169":  # response_ip
      semafor.insert(0,0)
    if aux[2]=="184.0.48.255":  # response_ip
      semafor.insert(0,1)
    #if aux[2]=="184.0.48.171":  # response_ip
      #semafor.insert(0,0)
    if aux[2]=="255.255.255.255":  # response_ip
      semafor.insert(0,0)




    #var=aux[4].split()
    #var[2]='\0'
    #print(var[2])
    #varnr=0;
    #variabila=""
    #for caracter in var[2]:
      #variabila[varnr]=caracter
      #if varnr==3:
      #  break
      #varnr+=1
    #print(aux[13])
    #if var[2][0:8]>="00:00:01" and aux[13]>"0":  # response_ip
    #  semafor.insert(0,1)
    #in var[2] and aux[8]>="39"

    #print(aux[12])
    #if "00:00:00" in var[2]:  # response_ip
    #  if aux[12] > "39":
    #    semafor.insert(0,1)
    #    print(aux[12])
    #print(aux[4]) #00:00:01

def soltask2(buffer,semafor):
  #print(buffer)
  #print("mere")
  #recunoastem daca are la finalenal .exe sau cv
  #verifinalecam daca e in baza de date
  #semafor =[0];
  verifflowdurat(buffer,semafor)
  #semafor = semafor;
  #semafor.insert(0,semafor[0]) # !!!!!!!!!

def task2():
    finamein="data/traffic/traffic.in"
    finameout="traffic-predictions.out"

    finale= open(finamein,"r")
    fonale= open(finameout,"w")

    vector=finale.readlines()
    #print(vector)
    #reading=vector.split()
    #print(vector[4]) e bine
    nr=0;
    for line in vector:
        semafor=[0]
        if(nr>0):
          soltask2(line,semafor)
          print(semafor[0], file=fonale)
        nr+=1
    #break
    finale.close()
    fonale.close()

def main():
    task1()
    task2()
##task2()
main()
