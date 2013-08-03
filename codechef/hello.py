#
# Problem: http://www.codechef.com/AUG13/problems/HELLO/
# Category: Simple coding
#
num_cases = int(raw_input())
for i in xrange(0, num_cases):
    usage = str(raw_input()).split()
    default = float(usage[0])
    minutes = int(usage[1])
    num_plans = int(usage[2])
    best_cost = minutes * default
    best_plan = 0
    for j in xrange(0, num_plans):
        plan = str(raw_input()).split()
        months = int(plan[0])
        per_call = float(plan[1])
        plan_cost = int(plan[2])
        this_cost = (minutes * months * per_call + plan_cost) / (months * 1.0)
        if this_cost < best_cost:
            best_cost = this_cost
            best_plan = j + 1
    print best_plan
