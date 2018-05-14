from pyrebase import pyrebase
import pygame
import nmap
import time
ip='192.168.18.0/24'
nm = nmap.PortScanner() 
status=True


file0="music3.ogg"
file2="en_effect.ogg"
pygame.mixer.init(frequency=22050, size=-16, channels=2, buffer=4096)
pygame.mixer.music.load(file0)
pygame.mixer.music.play()

main_sound=pygame.mixer.Sound(file0)
sub_sound=pygame.mixer.Sound(file2)


config = {
  "apiKey": "AIzaSyDidWeXVeIp5ZzTkilDbKuyv68NgtcWZBM",
  "authDomain": "networkeverything-203010.firebaseapp.com",
  "databaseURL": "https://networkeverything-203010.firebaseio.com",
  "storageBucket": "networkeverything-203010.appspot.com"
}

firebase = pyrebase.initialize_app(config)
db = firebase.database()

while status ==True:
	nm.scan(hosts=ip, arguments='-sP')
	for h in nm.all_hosts():
		if 'mac' in nm[h]['addresses']:
			addr=nm[h]['addresses']['mac']
			print(addr)
			all_users = db.child("Send").get()
			detectedKey=addr

			for user in all_users.each():
				if detectedKey == user.key():
					db.child("Send").child(user.key()).remove()
					db.child("Receive").child(addr)

					sub_sound.play()
					time.sleep(11)
					continue

