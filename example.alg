INTEGER PROCEDURE fibonachi(n); VALUE n;
BEGIN;
    INTEGER n;
    res := -1;
    IF n < 0 THEN
        WRITE( 'wrong n' )
    ELSE
    BEGIN 
        IF n = 0 THEN
            res := 0;
        ELSE
        BEGIN
            INTEGER a, b;
            a := 0; b := 1;
            FOR i := 1 STEP 1 UNTIL n DO
            BEGIN
                a := b;
                b := a + b;
                res : = b;
            END;
        END;
    END;
    WRITE( 'result', res )
END