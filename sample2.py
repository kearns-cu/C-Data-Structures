# this program has INCORRECT syntax, you should get an error at line 15

mylist = [(1,2),(3,4),(5,6)]
for i in range(len(mylist)):
    print(mylist[i])

x = []
while(len(x) < 3):
    x.append(mylist[0])
    print(x)

d = {
('a','b'):{[1,2,3]},
('c','d'):{[4,5,6]},
('e','f'):{[7],[8],[9]]}
}

print(d)
