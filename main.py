class Student:

    def __init__(self, id=0, name='', lop='', point=0):
        self.id = id
        self.name = name
        self.lop = lop
        self.point = point

    def getInfo(self,file):
        lines = file.read().split('\n')
        self.id = lines[0]
        self.name = lines[1]
        self.lop = lines[2]
        self.point = lines[3]

    def showInfo(self):
        print(f'{"Mã sinh viên" : <25} | {self.id}')
        print(f'{"Tên sinh viên" : <25} | {self.name}')
        print(f'{"Lớp" : <25} | {self.lop}')
        print(f'{"Điểm thi Tiếng Anh" : <25} | {self.point}')

class Dethi:

    def __init__(self, code):
        self.code = code

    def inputAnswer(self):
        i = input('Nhap ma de thi: ')
        name = 'dethi'+i+'.txt'
        with open(name,'r') as file:
            lines = file.readlines()
            for _ in lines:
                print(_)


# id = input('Nhap id: ')
# name = input('Nhap name: ')
# lop = input('Nhap lop: ')

sv1 = Student(106230038,"Nguyễn Văn An", "23KT", 9.6)
sv2 = Student()
with open("info.txt",encoding='UTF-8') as file:
    sv2.getInfo(file)
sv2.showInfo()
sv1.showInfo()

print("Xuất thông tin thành công!!")
