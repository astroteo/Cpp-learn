# python always allows a fucntion returning a function
def outer():
    def inner():
        print("HERE IS INNER TALKING")
    return inner

# the dual of callobacks fucntionality are python decorators
def decorator_func(func_decorated):
    def wrapper():
        print("before decorated function")
        func_decorated()
        print("after decorated function!")
    return wrapper

def func_to_be_decorated():
    print("I HAVE BEEN DECORATED")

@decorator_func
def func_properly_decorated():
    print("I HAVE BEEN DECORATED PROPERLY")



def main():
    print("here-we-are!")
    out = outer()
    out()
    print("PRIMITVE DECORATOR!")
    decorated_func = decorator_func(func_to_be_decorated)
    decorated_func()
    print("EFFECTIVE DECORATOR USAGE=>")
    ftpd = func_properly_decorated
    ftpd()



if __name__ == '__main__':
    main()
