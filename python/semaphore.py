import threading
import time

# Semáforo é um objeto de lock que controla o acesso a um recurso compartilhado entre múltiplas threads ou processos.

# Se uma thread deseja acessar o recurso, ela deve adquirir o semáforo.
# Se o semáforo estiver disponível, é permitido o acesso ao recurso.
# Se o semáforo não estiver disponível, a thread deve esperar até que o semáforo seja liberado.

# Inicializamos um semáforo passando um número de slots disponíveis.
# Ele mantém um contador interno que indica quantos slots estão disponíveis para que o acesso ao recurso seja permitido.

# Tipos de semáforos:
# - Semáforo binário: tem apenas dois estados (0 ou 1), semelhante a um
# - Semáforo contador: pode ter um número maior de estados, permitindo múltiplas threads acessarem o recurso de forma simultânea.

semaphore = threading.Semaphore(2)

def access_resource(thread_id):
    print(f"Thread {thread_id} is trying to access the resource.")
    semaphore.acquire()
    print(f"Thread {thread_id} has acquired the resource.")
    time.sleep(2)
    print(f"Thread {thread_id} is releasing the resource.")
    semaphore.release()

for i in range(4):
    t = threading.Thread(target=access_resource, args=(i,))
    t.start()