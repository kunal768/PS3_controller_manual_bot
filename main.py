from numpy import interp
import pygame ,sys
from time import sleep
import serial




global ser
# ser = serial.Serial('/dev/ttyACM0',115200)
ser = serial.Serial()
ser.baudrate = 115200
ser.timeout=1
ser.port = "/dev/ttyUSB0"
#ser.port = 'COM17'
ser.open()
sleep(1)
#global hat_up 
hat_up = 0
#global hat_down
hat_down = 0
#global hat_left
hat_left = 0
#global hat_right
hat_right = 0
#global up
up = 0
#global down
down = 0
#global left
left = 0
#global right
right = 0
#global start
start = 0
#global back
back = 0
#global front_left
front_left = 0
#global front_right
front_right = 0
#global left_x
left_x = 0
#global left_y
left_y = 0
#global right_x
right_x = 0
#global right_y
right_y = 0
#global lt1
lt1 = 0
#global rt1
rt1 = 0

left_x_dir = 1
left_y_dir = 1
right_x_dir = 1
right_y_dir = 1


def serial_print():
	#message=str(hat_up)+str(hat_down)+str(hat_left)+str(hat_right)+str(up)+str(down)+str(left)+str(right)+str(start)+str(back)+str(front_left)+str(front_right)+str(left_x)+str(left_y)+str(right_x)+str(right_y)+str(lt1)+str(rt1)
	global s
	s = ("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s")%(hat_up,hat_down,hat_left,hat_right,up,down,left,right,start,back,front_left,front_right,left_x,left_y,right_x,right_y,lt1,rt1,left_x_dir,left_y_dir,right_x_dir,right_y_dir)
	# ser.write("1".encode())
  # print(s.encode())

	ser.write(s.encode())
  # print(s.encode())
	print(s)
	# print(s.encode())
	
	# sleep(0.5)
	
	#s = "%s" %(message)
	#print(len(message))
	#ser.write(s.encode())
	
#def rangeMap(number):
 # return int(interp(number,[-1.0, 1.0] , [0,9]))
def rangeMap(value):
  istart = -1.0
  istop = 0.99
  ostart = -9
  ostop = 9
  val =  ostart + (ostop - ostart) * ((value - istart) / (istop - istart))
  return int(val)




# setting up pygame window
pygame.init() 
window = pygame.display.set_mode((200,200),0,32)

# Joysticks connected to the computer
joystick_count = pygame.joystick.get_count()
print ("There is " + str(joystick_count) + " joystick/s")

if joystick_count == 0:
    # if no joysticks, quit program safely
    print ("Error, I did not find any joysticks")
    pygame.quit()
    sys.exit()
else:
    # initialise joystick
    joystick = pygame.joystick.Joystick(0)
    joystick.init()

axes = joystick.get_numaxes()
buttons = joystick.get_numbuttons()
hats = joystick.get_numhats()

print( "There is " + str(axes) + " axes")
print("There is " + str(buttons) + " button/s")
print("There is " + str(hats) + " hat/s")


def clear_all_axis():
  global left_x_dir
  left_x_dir = 1
  global right_x_dir
  right_x_dir = 1
  global left_y_dir
  left_y_dir = 1
  global right_y_dir
  right_y_dir = 1
 
  global left_x
  left_x = 0
  global left_y
  left_y = 0
  global right_x
  right_x = 0
  global right_y
  right_y = 0
  global lt1
  lt1 = 0
  global rt1
  rt1 = 0


def clear_all_buttons():
	global up
	up = 0
	global down
	down = 0
	global left
	left = 0
	global right
	right = 0
	global start
	start = 0
	global back
	back = 0
	global front_left
	front_left = 0
	global front_right
	front_right = 0


def clear_all_hats():
	global hat_up 
	hat_up = 0
	global hat_down
	hat_down = 0
	global hat_left
	hat_left = 0
	global hat_right
	hat_right = 0



def getAxis(number):
    # when nothing is moved on an axis, the VALUE IS NOT EXACTLY ZERO
    # so this is used not "if joystick value not zero"
    #print(number)
    if joystick.get_axis(number) < -.1 or joystick.get_axis(number) > .1:
      global left_x_dir
      if number is 0 :
                    print(number)
                    global left_x
                    left_x = ((rangeMap(joystick.get_axis(number))))
                    if(left_x < 0):
                            left_x_dir = 0
                    if(left_x > 0):
                      left_x_dir = 2
                    left_x = abs((rangeMap(joystick.get_axis(number))))
      if number is 1:
              #print(number)
              global left_y,left_y_dir
              left_y = ((rangeMap(joystick.get_axis(number))))
              if(left_y < 0):
                #global left_y_dir
                left_y_dir = 0
              if(left_y > 0) :
                #global left_y_dir
                left_y_dir = 2
              left_y = abs((rangeMap(joystick.get_axis(number))))


      if number is 3:
              #print(number)
              global right_y
              right_y = ((rangeMap(joystick.get_axis(number))))
              right_y = abs((rangeMap(joystick.get_axis(number))))
      if number is 4:
              #print(number)
              global right_x,right_x_dir
              right_x = ((rangeMap(joystick.get_axis(number))))
              if(right_x < 0):
                global right_x_dir
                right_x_dir = 0
              if(right_x > 0):
                #global right_x_dir
                right_x_dir = 2
              right_x = abs((rangeMap(joystick.get_axis(number))))

      if (number is 2 ) and (joystick.get_axis(number) > 0):
                #print(number)
                global lt1,right_y_dir
                lt1 = ((rangeMap(joystick.get_axis(number))))
                right_y_dir = 0
                lt1 = abs((rangeMap(joystick.get_axis(number))))

      if (number is 2 ) and (joystick.get_axis(number) < 0):
                #print(number)
                global rt1,right_y_dir
                rt1 = abs((rangeMap(joystick.get_axis(number))))
                right_y_dir = 2
                rt1 = abs((rangeMap(joystick.get_axis(number))))
      #else:
      #	clear_all_axis()

#.999969482421875
# -1.0
def getButton(number):
    # returns 1 or 0 - pressed or not
    if joystick.get_button(number):
      # just prints id of button
      #print("Button ID is %s" %(number))
      if number is 0:
      	global down
      	down = 1
      if number is 1:
      	global right
      	right = 1
      if number is 2:
      	global left
      	left = 1
      if number is 3:
      	global up
      	up = 1
      if number is 4:
      	global front_left
      	front_left = 1
      if number is 5:
      	global front_right
      	front_right = 1
      if number is 6:
      	global back
      	back = 1
      if number is 7:
      	global start
      	start = 1
      #else:
      #	clear_all_buttons()


def getHat(number):
    if joystick.get_hat(number) != (0,0):
      # returns tuple with values either 1, 0 or -1
      #print("Hat value is %s, %s" %(joystick.get_hat(number)[0],joystick.get_hat(number)[1]))
      #print ("Hat ID is %s" %(number))
      if (joystick.get_hat(number)[0] is 0 ) and (joystick.get_hat(number)[1] is 1):
      	global hat_up
      	hat_up = 1
      if (joystick.get_hat(number)[0] is 0 ) and (joystick.get_hat(number)[1] is -1):
      	global hat_down
      	hat_down = 1
      if (joystick.get_hat(number)[0] is -1 ) and (joystick.get_hat(number)[1] is 0):
      	global hat_left
      	hat_left = 1
      if (joystick.get_hat(number)[0] is 1 ) and (joystick.get_hat(number)[1] is 0):
      	global hat_right
      	hat_right = 1
      	#clear_all_hats()


while True:
    for event in pygame.event.get():
      # loop through events, if window shut down, quit program
      if event.type == pygame.QUIT:
        pygame.quit()
        sys.exit()
    if axes != 0:
      for i in range(axes):
        getAxis(i)
    if buttons != 0:
      for i in range(buttons):
        getButton(i)
    if hats != 0:
      for i in range(hats):
        getHat(i)
    # ser.flush()
    # ser.write("1".encode())
    serial_print()
    #ser.flush()
    clear_all_buttons()
    clear_all_hats()
    clear_all_axis()
    #print(ser.read())
    
    # print(s.encode())
    #int(ser.read())
    sleep(1)


# 14 pin error on board
##
