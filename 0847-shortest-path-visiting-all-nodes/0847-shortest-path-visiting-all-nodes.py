class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        target=(1<<len(graph))-1
        que=[(i,1<<i) for i in range(len(graph))]
        visited=set()
        step=0
        while que:
            tmp=[]
            for q in que:
                if q in visited:
                    continue
                visited.add(q)
                node,mask=q
                if mask==target:
                    return step
                for nxt in graph[node]:
                    tmp.append((nxt,mask|1<<nxt))
            que=tmp
            step+=1
        return -1