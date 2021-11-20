class Board:
	def __init__(self):
		self.board = []
		for i in range(8):
			col = []
			for j in range(8):
				col.append(0)
			self.board.append(col)

	def minSteps(self, sourceX, sourceY, destX, destY):

		if(sourceX >= 8 or sourceX < 0 or sourceY >= 8 or sourceX < 0):
			return -1

		if(sourceX == destX and sourceY == destY):
			return 0
		
		step = 0

		dx = [1,1,-1,-1,2,2,-2,-2]
		dy = [2,-2,2,-2,1,-1,1,-1]

		queue = []
		addStep = True

		queue.append((sourceX,sourceY))
		self.board[sourceX][sourceY] = 1
		queue.append(addStep)

		while queue:
			front = queue.pop(0)
			if type(front) == bool:
				if(queue):
					queue.append(addStep)
					step = step + 1
				else:
					break
			else:
				currX = front[0]
				currY = front[1]

				if currX == destX and currY == destY:
					return step

				for i in range(8):
					nextX = currX + dx[i]
					nextY = currY + dy[i]
					if(nextX >= 0 and nextX < 8 and nextY >=0 and nextY < 8 and self.board[nextX][nextY]==0):
						queue.append((nextX,nextY))
						self.board[nextX][nextY] = 1


chess = Board();

sourceX = int(input("\nEnter starting X position of the Knight: "))
sourceY = int(input("\nEnter starting Y position of the Knight: "))
destX = int(input("\nEnter final X position of the Knight: "))
destY = int(input("\nEnter final Y position of the Knight: "))

print(chess.minSteps(sourceX,sourceY,destX,destY))
