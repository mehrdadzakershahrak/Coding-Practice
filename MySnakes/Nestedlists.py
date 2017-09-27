students = []
for _ in range(int(raw_input())):
    name = raw_input()
    score = float(raw_input())
    students.append([name,score])
    
results = sorted(list(set([score for name, score in students])))[1]
print('\n'.join([a for a,b in sorted(students) if b == results]))
