/*
 * std.h
 *
 * Created: 23/5/2023 7:34:19 AM
 *  Author: Hamsters
 */


#ifndef STD_H_
#define STD_H_


typedef unsigned    char                uint8_t_;       /* 1 byte , 0 -> 255 */
typedef unsigned    short   int         uint16_t_;      /* 2 bytes, 0 -> 65,535 */
typedef unsigned    long    int         uint32_t_;      /* 4 bytes, 0 -> 4,294,967,295 */
typedef unsigned    long    long int    uint64_t_;      /* 8 bytes, 0 -> 18,446,744,073,709,551,615 */

typedef signed      char                sint8_t_;       /* 1 byte , -128 -> 127 */
typedef signed      short   int         sint16_t_;      /* 2 bytes, -32,768 -> 32,767 */
typedef signed      long    int         sint32_t_;      /* 4 bytes, -2,147,483,648 -> 2,147,483,647 */
typedef signed      long    long int    sint64_t_;      /* 8 bytes, -9,223,372,036,854,775,807 -> 9,223,372,036,854,775,807 */

typedef                     float       f32_t_;         /* 4 bytes, 3.4e-38 -> 3.4e+38 */
typedef                     double      f64_t_;         /* 8 bytes, 1.7e-308 -> 1.7e+308 */

typedef                     void        vd_t_;


#define TRUE        1
#define FALSE       0

#define NULL        (0)
#define NULL_PTR    ((void *) 0)

#endif /* STD_H_ */