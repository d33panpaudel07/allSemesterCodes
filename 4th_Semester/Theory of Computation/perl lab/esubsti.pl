$line = "liquid will remain liquid until it is evaporated";  
$line =~ s/liquid/solid/;  
print "$line\n";  
print"\n";  
$line = "liquid will remain liquid until it is solidified";  
$line =~ s/liquid/solid/g;  
print "$line\n";  