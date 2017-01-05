--default variable is global
--local variable 
b="global"

function myfunction()

   local b="local variable"
   a="gloable variable"
   print(a,b)

end

myfunction()
print(a,b)
