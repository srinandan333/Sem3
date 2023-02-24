import re
pattern = '^[_a-zA-Z0-9-]+(\.[_a-zA-Z0-9-]+)*@[a-zA-Z0-9-]+(\.[a-zA-Z0-9-]+)*\.(([0-9]{1,3})|([a-zA-Z]{2,3})|(com|edu|info|museum|name))$'
while True:
  test_string = input("Enter email of choice:")
  result = re.match(pattern, test_string)
  if result:
    print("Valid email.")
  else:
    print("Invalid email.")
  print("1.Continue 2. Exit")
  ch= int(input("Enter choice:"))
  if ch==2:
    break
