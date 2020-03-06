#!/usr/bin/python

def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        return False

## Open the file with read only permit
approx_f = open('approx_prices_64K.txt', "r")
prec_f = open('prices_64K.txt', "r")
error_f = open('error_64K.txt', "w")

approx_line = approx_f.readline()
prec_line = prec_f.readline()

i = 0;
big_err = 0;
totol_error = 0.0;
biggest_err = 0;
while approx_line and prec_line:
    i += 1
    #print approx_line
    #print prec_line
    #print is_number(approx_line)
    a = float(approx_line)
    b = float(prec_line)
    #print str(a) + ' ' + str(b)
    if a < 0:
        a = 0
    if b != 0:
        error = abs((a - b) / b)
    else:
        if a == 0:
            error = 0
        else:
            error = 1
#        error = 0
#    if error > 100:
#        big_err += 1
#        print str(a) + ' ' + str(b)
    if error > biggest_err:
        biggest_err = error
    error_pcnt = error * 100
    error_f.write(str(a) + '\t' + str(b) + '\t')
    error_f.write(str(error_pcnt) + '\n')
    totol_error += error
    #print 'error: ' + str(error)
    approx_line = approx_f.readline()
    prec_line = prec_f.readline()

print 'totol error: ' + str(totol_error / i) + ', # of pairs: ' + str(i)
print '\t# big error: ' + str(big_err) + ', largest error: ' + str(biggest_err)

approx_f.close()
prec_f.close()
error_f.close()

