tuple1 = ["id", "name", "age"], ["pk", "name1", "age1"]
tuple2 = ('1', '2', '3'), ('1', '2', '5')
print(type(tuple1))
print(type(tuple2))
print(tuple1[1][2])
# print(tuple2.__getitem__(1)[1])
print(tuple2[1][1])

print()
list1 = ["id", "haha"]
list2 = [["id", "name"], ["age", "address"]]
print(type(list1))
print(type(list2))
print(list2[1][1])
print()



"""
This is a multi line comment
SO
    TUPLE USE ( )
    SET USE { }
    LIST USE [ ]
"""