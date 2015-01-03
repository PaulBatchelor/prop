use 5.010;
use strict;

my $width = 400;
my $height = 100;
my $border = 10;
my $linewidth = $height - 2 * $border;

my @ratios = qw(3 1 1 1);

my $sum = 0;

foreach(@ratios){ $sum += abs $_ };

my $incr = 1.0 * ($width - 2 * $border) / $sum;

print <<END;
%!PS
%%BoundingBox: 0 0 $width $height

/lineWidth $linewidth def

/line
{
newpath
0 0 moveto
0 lineWidth lineto
}def 

2 setlinewidth 
10 10 translate
END

#$incr 0 translate

foreach(@ratios)
{
if($_ > 0 ) {
print("0 0 0 setrgbcolor\n");
}else{
print("0.91 0.91 0.91 setrgbcolor\n");
}
print("line stroke\n");
print(abs int $incr * $_ ," 0 translate\n");
}

print <<END;

showpage

END
