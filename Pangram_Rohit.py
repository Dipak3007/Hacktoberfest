#program to check whether the Given String is pangram or not

s=input("Enter a string : ")
a='abcdefghijklmnopqrstuvwxyz'
f=0
for i in a:
    if(i not in s.lower()):
        f=1
        break
if(f==0):
    print(s," is pangram.")
else:
    print(s," is not pangram.")
