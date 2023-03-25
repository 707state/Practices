class ASCII:

    def __int__(self,tar:str):
        self.string=tar
    def makeASCII(self)->list:
        ASCIIList=[]
        for i in self.string:
            ASCIIList.append(str(ord(i)))
        return ASCIIList
if __name__=="__main__":
    temp=input("输入你的目标字符串: ")
    ans=ASCII()
    ans.__int__(temp)
    print(' '.join(ans.makeASCII()))