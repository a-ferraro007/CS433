from multiprocessing import Process
import os
import time

def handle_fork():
    print("Process spawned \n")

def main():
    p = Process(target=handle_fork)
    p.start()
    p.join()

    print(f"Parent Process id: {os.getppid()}")
    print(f"Child Process id: {os.getpid()}")

    time.sleep(60)



if __name__ == "__main__":
    main()
