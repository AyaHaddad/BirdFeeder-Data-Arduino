
import serial 
import MySQLdb
import time

dbConn = MySQLdb.connect("localhost","root","","bird_feed") or die ("could not connect to database")
#open a cursor to the database
cursor = dbConn.cursor()

device = 'COM6' #this will have to be changed to the serial port you are using
try:
  print "Trying...",device 
  arduino = serial.Serial(device, 9600) 
except: 
  print "Failed to connect on",device    

while True:
    try:
      time.sleep(1)
      data = arduino.readline()  #read the data from the arduino
      print data
      pieces = data.split(" ")  #split the data by the tab
      print "piece 1 : ", pieces[0]
      print "piece 2 : ", pieces[1]
      print "piece 3 : ", pieces[2]
      #Here we are going to insert the data into the Database
      try:
        cursor.execute("INSERT INTO seed_weight (weight) VALUES (%s)", (pieces[0]))
        cursor.execute("INSERT INTO tension (tension) VALUES (%s)", (pieces[1]))
        cursor.execute("INSERT INTO water_level (level) VALUES (%s)", (pieces[2]))
        dbConn.commit() #commit the insert
        #cursor.close()  #close the cursor

      except MySQLdb.IntegrityError:
        print "failed to insert data"

      #finally:
        #cursor.close()  #close just incase it failed
    except:
      print "Failed to get data from Arduino!"

            
            
