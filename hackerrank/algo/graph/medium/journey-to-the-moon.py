from collections import defaultdict
n,e = map(int,raw_input().split())
num = n
visited = [False]*n
class Graph:
	def __init__(self):
		self.graph = defaultdict(list)

	def addEdge(self,u,v):
		self.graph[u].append(v)	

	def bfs(self,s):
		queue = []
		global num
		queue.append(s)
		visited[s]=True
		count = 1
		while queue:
			s = queue.pop(0)
			#print s,
			for v in self.graph[s]:
				if visited[v]==False:
					visited[v]=True
					queue.append(v)
					count+=1
		num-=count
		#print
		return count

	def bfs_travelsal(self,n):
		p = list()
		# k = self.bfs(0)
		# p.append(k)
		j = list(self.graph.keys())
		for u in j:
			if visited[u]==False:
				k = self.bfs(u)
				p.append(k)
		return p



g = Graph()
for i in range(0,e):
	u,v = map(int,raw_input().split())
	g.addEdge(u,v)
	g.addEdge(v,u)

p = g.bfs_travelsal(n)
num-=1
w = num*(num+1)/2
ans = 0
num+=1
t = sum(p)
for i in range(0,len(p)):
	ans += p[i]*(t+num-p[i])
	t-=p[i]
ans+=w
print ans