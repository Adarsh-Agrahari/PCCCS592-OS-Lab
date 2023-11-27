# 1 import libraries
import threading, time, random

class ReaderWriterProblem:
    def __init__(self):
        self.resource = 0
        self.readers = 0
        self.mutex = threading.Semaphore(1)
        self.resource_lock = threading.Semaphore(1)

    def reader(self, id):
        while True:
            self.mutex.acquire()
            self.readers += 1
            if self.readers == 1:
                self.resource_lock.acquire()
            self.mutex.release()

            # Read the resource
            print(f"Reader {id} is reading the resource: {self.resource}")

            self.mutex.acquire()
            self.readers -= 1
            if self.readers == 0:
                self.resource_lock.release()
            self.mutex.release()
            time.sleep(random.randint(1, 3))

    def writer(self, id):
        while True:
            self.resource_lock.acquire()
            # Write to the resource
            self.resource += 1
            print(f"Writer {id} is writing to the resource. New value: {self.resource}")
            self.resource_lock.release()
            time.sleep(random.randint(1, 3))

# Creating an instance of the ReaderWriterProblem
problem = ReaderWriterProblem()

# Creating reader and writer threads
for i in range(5):
    reader_thread = threading.Thread(target=problem.reader, args=(i,))
    reader_thread.start()

for i in range(2):
    writer_thread = threading.Thread(target=problem.writer, args=(i,))
    writer_thread.start()
