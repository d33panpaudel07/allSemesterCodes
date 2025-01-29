# substr(var, index, length): returns the substring from string var, starting from position index, of length. String index begins at 0. You can also use substr to modify the original string. For example,


my $msg = 'Perl is fun!';

my $adj = substr($msg, 8, 3);      # Extract a portion of string

print $adj, "\n";                  # 'fun'

print substr($msg, 8), "\n";       # 'fun!'

substr($msg, 8, 3) = 'quite cool'; # Modify a portion of string

print $msg, "\n";                  # 'Perl is quite cool!'

# index(string, substring): return the index of the substring in string, or -1 if not found.
# rindex(string, substring): return the index but searching from the right.
# length(string): returns the number of characters in string.
# lc(string): returns a lowercase string.
# uc(string): returns an uppercase string.
# lcfirst(string): returns a first-letter lowercase string.
# ucfirst(string): returns a first-letter uppercase string.