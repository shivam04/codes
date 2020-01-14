# Your task is to complete this function
# Function should return True/False or 1/0
# Graph(graph) is a defaultict of type List
# n is no of Vertices
def isCyclicUtil(k,visit,graph,stack):
    visit[k] = 1
    stack[k] = 1
    for i in graph[k]:
        if visit[i]==0 and isCyclicUtil(i,visit,graph,stack):
            return True
        elif stack[i]==1:
            return True
    stack[k] =False
    return False
def isCyclic(n, graph):
    visit = [0]*n
    stack = [0]*n
    i = 0
    #print(graph.keys())
    for k in range(0,n):
        if(isCyclicUtil(k,visit,graph,stack)):
            return True
    return False
            