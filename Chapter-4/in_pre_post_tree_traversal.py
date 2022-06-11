class Node:
	def __init__(self, key):
		self.left = None
		self.right = None
		self.val = key


def In_order(root):
	if root:
		In_order(root.left)
		print(root.val,end=" ")
		In_order(root.right)

def Post_order(root):
	if root:
		Post_order(root.left)
		Post_order(root.right)
		print(root.val,end=" ")


def Pre_order(root):
	if root:
		print(root.val,end=" ")
		Pre_order(root.left)
		Pre_order(root.right)


root = Node(1)
root.left = Node(4)
root.right = Node(3)
root.left.left = Node(9)
root.left.right = Node(20)

print(" PREORDER TRAVERSAL: ",end="")
Pre_order(root)
print()

print(" INORDER TRAVERSAL: ",end="")
In_order(root)
print()

print(" POSTORDER TRAVERSAL: ",end="")
Post_order(root)
print()
