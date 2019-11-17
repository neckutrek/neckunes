import time

def mainLoop(_fps, _func):
   fps = _fps
   run = True
   start = time.time()
   while run:
      _func(time.time())
      end = time.time()
      if end-start < 1/fps:
         t = 1/fps - (end-start)
         time.sleep( t )
      start = time.time()

def main():
   def p(t):
      print("time: {}".format(t))
   
   mainLoop(4, p)
   