#!/usr/bin/env perl
use strict;
use warnings;
while (<>) # Read input from command-line into default variable $_

{              
   print m/[0-9]+/ ? "Accept\n" : "Reject\n";   # one or more digits?
}

