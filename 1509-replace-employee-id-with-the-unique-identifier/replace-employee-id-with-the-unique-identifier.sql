select y.unique_id, x.name
from Employees x
left join EmployeeUNI y on x.id = y.id