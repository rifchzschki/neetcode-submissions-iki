from collections import deque
class Solution:
    stackPath = deque()
    def simplifyPath(self, path: str) -> str:
        i=0
        currentSubpath=""
        while(i<=len(path)):
            if(i==len(path) or path[i]=='/'):
                if(currentSubpath!="" and currentSubpath!="."):
                    if(currentSubpath==".."):
                        if(len(self.stackPath)):
                            self.stackPath.pop()
                    else:
                        self.stackPath.append(currentSubpath)
                if(i==len(path)): break
                currentSubpath=""
            else:
                currentSubpath+=path[i]
            i+=1
        
        res = ""
        while(len(self.stackPath)!=0):
            subPath = self.stackPath.popleft()
            res+=f"/{subPath}"
        return res if len(res)>0 else "/";