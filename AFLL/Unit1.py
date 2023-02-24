def q0(c):
    if(c=='a'):
        dfa=1
    elif(c=='b'):
        dfa=5
    else:
        dfa=-1
    return dfa

def q1(c):
    if(c=='a'):
        dfa=5
    elif(c=='b'):
        dfa=2
    else:
        dfa=-1
    return dfa

def q2(c):
    if(c=='a'):
        dfa=3
    elif(c=='b'):
        dfa=2
    else:
        dfa=-1
    return dfa

def q3(c):
    if(c=='a'):
        dfa=3
    elif(c=='b'):
        dfa=4
    else:
        dfa=-1
    return dfa

def q4(c):
    if(c=='a'):
        dfa=3
    elif(c=='b'):
        dfa=2
    else:
        dfa=-1
    return dfa

def q5(c):
        dfa=-1
        return dfa

def myfun(str):
    l=len(str)
    dfa=0
    for i in range(l):
        if dfa==0:
            dfa=q0(str[i])
        elif dfa==1:
            dfa=q1(str[i])
        elif dfa==2:
            dfa=q2(str[i])
        elif dfa==3:
            dfa=q3(str[i])
        elif dfa==4:
            dfa=q4(str[i])
        elif dfa==5:
            dfa=q5(str[i])
        else:
            return 0
    if(dfa==4):
        return 1
    else:
        return 0

while True:
    if __name__ == "__main__" :  
        str=input("Enter string:")
        if (myfun(str)) :  
            print("ACCEPTED")   
        else:  
            print("NOT ACCEPTED") 
    print("1.Continue 2. Exit")
    ch= int(input("Enter choice:"))
    if ch==2:
        break

