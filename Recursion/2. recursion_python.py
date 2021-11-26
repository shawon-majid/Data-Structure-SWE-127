def f(s, e):
    if(s > e):
        print("Error enter correctly")
        return
    elif(s == e):
        print(s);
        return
    
    print(s);
    ss = chr(ord(s) + 1);
    f(ss, e);
    
    
def main():
    print('Enter the starting character: ')
    s = input()
    print('Enter the ending character: ')
    e = input()    
    
    f(s, e);
    

if __name__ == '__main__':
    main()
