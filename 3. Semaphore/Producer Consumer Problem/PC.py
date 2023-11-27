# 1 import libraries
import threading, time
 
# 2 Shared Memory variables
capacity = 5
buffer = [-1]*capacity
In = 0
Out = 0 
 
# 3 Declaring Semaphores
mutex = threading.Semaphore()
empty = threading.Semaphore(capacity)
full = threading.Semaphore(0)
  
# 4 Producer Thread Class
class Producer(threading.Thread):
  def run(self):
     
    global capacity, buffer, In, Out
    global mutex, empty, full
     
    items_produced = 0
    counter = 0
     
    while items_produced < 20:
      empty.acquire()
      mutex.acquire()
       
      counter += 1
      buffer[In] = counter
      In = (In + 1)%capacity
      print("Producer produced : ", counter)
       
      mutex.release()
      full.release()
       
      time.sleep(1)
       
      items_produced += 1
 
# 5 Consumer Thread Class
class Consumer(threading.Thread):
  def run(self):
     
    global capacity, buffer, In, Out, counter
    global mutex, empty, full
     
    items_consumed = 0
     
    while items_consumed < 20:
      full.acquire()
      mutex.acquire()
       
      item = buffer[Out]
      Out = (Out + 1)%capacity
      print("Consumer consumed item : ", item)
       
      mutex.release()
      empty.release()      
       
      time.sleep(2.5)
       
      items_consumed += 1
 
# 6 Creating Threads
producer = Producer()
consumer = Consumer()
 
# 7 Starting Threads
producer.start()
consumer.start()
 
# 8 Waiting for threads to complete
producer.join()
consumer.join()