/*****************************************************************************
 *
 * \file
 *
 * \brief This file specifies the functions optimized for the AVR32 UC3 target.
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 *****************************************************************************/
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#ifndef __AVR32UC_OPTIM_H__
#define __AVR32UC_OPTIM_H__

// Filtering module
// FIR filters
#undef  TARGET_SPECIFIC_FILT16_FIR
#undef  TARGET_SPECIFIC_FILT32_FIR
// IIR filters
#define TARGET_SPECIFIC_FILT16_IIR  1
#undef  TARGET_SPECIFIC_FILT32_IIR
// Partial IIR filters
#define TARGET_SPECIFIC_FILT16_IIRPART  1
#undef  TARGET_SPECIFIC_FILT32_IIRPART
// LMS filters
#define TARGET_SPECIFIC_FILT16_LMS  1
#define TARGET_SPECIFIC_FILT32_LMS  1
// NLMS filters
#define TARGET_SPECIFIC_FILT16_NLMS 1
#define TARGET_SPECIFIC_FILT32_NLMS 1
// Low pass FIR filter design
#undef TARGET_SPECIFIC_FILT16_LPFIRDESIGN
#undef TARGET_SPECIFIC_FILT32_LPFIRDESIGN

// Operators module
// Cosine
#undef  TARGET_SPECIFIC_OP16_COS
#undef  TARGET_SPECIFIC_OP32_COS
// Sine
#undef  TARGET_SPECIFIC_OP16_SIN
#undef  TARGET_SPECIFIC_OP32_SIN
// Arc cosine
#undef  TARGET_SPECIFIC_OP16_ACOS
#undef  TARGET_SPECIFIC_OP32_ACOS
// Arc sine
#undef  TARGET_SPECIFIC_OP16_ASIN
#undef  TARGET_SPECIFIC_OP32_ASIN
// Absolute
#undef  TARGET_SPECIFIC_OP16_ABS
#undef  TARGET_SPECIFIC_OP32_ABS
// Square root
#define TARGET_SPECIFIC_OP16_SQRT   1
#undef  TARGET_SPECIFIC_OP32_SQRT
// Exponential
#undef  TARGET_SPECIFIC_OP16_EXP
#undef  TARGET_SPECIFIC_OP32_EXP
// Natural logarithm
#define TARGET_SPECIFIC_OP16_LN     1
#undef  TARGET_SPECIFIC_OP32_LN
// Binary logarithm
#undef  TARGET_SPECIFIC_OP16_LOG2
#undef  TARGET_SPECIFIC_OP32_LOG2
// Common logarithm
#undef  TARGET_SPECIFIC_OP16_LOG10
#undef  TARGET_SPECIFIC_OP32_LOG10
// Power
#undef  TARGET_SPECIFIC_OP16_POW
#undef  TARGET_SPECIFIC_OP32_POW
// Random
#undef  TARGET_SPECIFIC_OP16_RAND
#undef  TARGET_SPECIFIC_OP32_RAND

// Signal generation module
// Cosinusoidal
#undef  TARGET_SPECIFIC_GEN16_COS
#undef  TARGET_SPECIFIC_GEN32_COS
// Sinusoidal
#undef  TARGET_SPECIFIC_GEN16_SIN
#undef  TARGET_SPECIFIC_GEN32_SIN
// Noise
#undef  TARGET_SPECIFIC_GEN16_NOISE
#undef  TARGET_SPECIFIC_GEN32_NOISE
// Square
#undef  TARGET_SPECIFIC_GEN16_SQR
#undef  TARGET_SPECIFIC_GEN32_SQR
// Rectangle
#undef  TARGET_SPECIFIC_GEN16_RECT
#undef  TARGET_SPECIFIC_GEN32_RECT
// Saw tooth
#undef  TARGET_SPECIFIC_GEN16_SAW
#undef  TARGET_SPECIFIC_GEN32_SAW
// Dirac comb
#undef  TARGET_SPECIFIC_GEN16_DCOMB
#undef  TARGET_SPECIFIC_GEN32_DCOMB
// Ramp
#undef  TARGET_SPECIFIC_GEN16_RAMP
#undef  TARGET_SPECIFIC_GEN32_RAMP
// Step
#undef  TARGET_SPECIFIC_GEN16_STEP
#undef  TARGET_SPECIFIC_GEN32_STEP
// Dirac
#undef  TARGET_SPECIFIC_GEN16_DIRAC
#undef  TARGET_SPECIFIC_GEN32_DIRAC

// Transforms module
// Real to complex FFT
#define TARGET_SPECIFIC_TRANS16_REALCOMPLEXFFT  1
#undef  TARGET_SPECIFIC_TRANS32_REALCOMPLEXFFT
// Complex FFT
#define TARGET_SPECIFIC_TRANS16_COMPLEXFFT      1
#undef  TARGET_SPECIFIC_TRANS32_COMPLEXFFT
// Complex inverse FFT
#define TARGET_SPECIFIC_TRANS16_COMPLEXIFFT     1
#undef  TARGET_SPECIFIC_TRANS32_COMPLEXIFFT

// Vectors module
// Addition
#define TARGET_SPECIFIC_VECT16_ADD      1
#define TARGET_SPECIFIC_VECT32_ADD      1
// Subtraction
#define TARGET_SPECIFIC_VECT16_SUB      1
#define TARGET_SPECIFIC_VECT32_SUB      1
// Addition and saturation
#undef TARGET_SPECIFIC_VECT16_ADD_AND_SAT
#undef TARGET_SPECIFIC_VECT32_ADD_AND_SAT
// Addition with a real
#undef  TARGET_SPECIFIC_VECT16_REALADD
#undef  TARGET_SPECIFIC_VECT32_REALADD
// Subtraction with a real
#undef  TARGET_SPECIFIC_VECT16_REALSUB
#undef  TARGET_SPECIFIC_VECT32_REALSUB
// Multiplication with a real
#define TARGET_SPECIFIC_VECT16_REALMUL  1
#define TARGET_SPECIFIC_VECT32_REALMUL  1
// Division with a real
#define TARGET_SPECIFIC_VECT16_REALDIV  1
#undef  TARGET_SPECIFIC_VECT32_REALDIV
// Multiplication with an integer
#undef  TARGET_SPECIFIC_VECT16_INTMUL
#undef  TARGET_SPECIFIC_VECT32_INTMUL
// Division with an integer
#undef  TARGET_SPECIFIC_VECT16_INTDIV
#undef  TARGET_SPECIFIC_VECT32_INTDIV
// Dot multiplication
#define TARGET_SPECIFIC_VECT16_DOTMUL   1
#undef  TARGET_SPECIFIC_VECT32_DOTMUL
// Dot division
#define TARGET_SPECIFIC_VECT16_DOTDIV   1
#undef  TARGET_SPECIFIC_VECT32_DOTDIV
// Power
#undef  TARGET_SPECIFIC_VECT16_POW
#undef  TARGET_SPECIFIC_VECT32_POW
// Minimum
#undef  TARGET_SPECIFIC_VECT16_MIN
#define TARGET_SPECIFIC_VECT32_MIN      1
// Maximum
#undef  TARGET_SPECIFIC_VECT16_MAX
#define TARGET_SPECIFIC_VECT32_MAX      1
// Negate
#define TARGET_SPECIFIC_VECT16_NEG      1
#define TARGET_SPECIFIC_VECT32_NEG      1
// Copy
#undef  TARGET_SPECIFIC_VECT16_COPY
#undef  TARGET_SPECIFIC_VECT32_COPY
// Zero padding
#undef  TARGET_SPECIFIC_VECT16_ZEROPAD
#undef  TARGET_SPECIFIC_VECT32_ZEROPAD
// Convolution
#undef  TARGET_SPECIFIC_VECT16_CONV
#undef  TARGET_SPECIFIC_VECT32_CONV
// Partial convolution
#define TARGET_SPECIFIC_VECT16_CONVPART 1
#define TARGET_SPECIFIC_VECT32_CONVPART 1
// Complex conjugate
#define TARGET_SPECIFIC_VECT16_COMPLEXCONJ  1
#undef  TARGET_SPECIFIC_VECT32_COMPLEXCONJ

// Windowing module
// Rectangular
#undef TARGET_SPECIFIC_WIN16_RECT
#undef TARGET_SPECIFIC_WIN32_RECT
// Bartlett
#undef  TARGET_SPECIFIC_WIN16_BART
#undef  TARGET_SPECIFIC_WIN32_BART
// Blackman
#undef  TARGET_SPECIFIC_WIN16_BLACK
#undef  TARGET_SPECIFIC_WIN32_BLACK
// Hamming
#undef  TARGET_SPECIFIC_WIN16_HAMM
#undef  TARGET_SPECIFIC_WIN32_HAMM
// Gauss
#undef  TARGET_SPECIFIC_WIN16_GAUSS
#undef  TARGET_SPECIFIC_WIN32_GAUSS
// Hanning
#undef  TARGET_SPECIFIC_WIN16_HANN
#undef  TARGET_SPECIFIC_WIN32_HANN
// Kaiser
#undef  TARGET_SPECIFIC_WIN16_KAISER
#undef  TARGET_SPECIFIC_WIN32_KAISER
// Welch
#undef  TARGET_SPECIFIC_WIN16_WELCH
#undef  TARGET_SPECIFIC_WIN32_WELCH

#endif // __AVR32UC_OPTIM_H__
