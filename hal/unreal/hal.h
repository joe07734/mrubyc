/*! @file
  @brief
  Hardware abstraction layer
        for Unreal Engine

  <pre>
  Copyright (C) 2015- Kyushu Institute of Technology.
  Copyright (C) 2015- Shimane IT Open-Innovation Center.

  This file is distributed under BSD 3-Clause License.
  </pre>
*/

#ifndef MRBC_SRC_HAL_H_
#define MRBC_SRC_HAL_H_

/***** Feature test switches ************************************************/
/***** System headers *******************************************************/
//#include <unistd.h>


/***** Local headers ********************************************************/
/***** Constant values ******************************************************/
/***** Macros ***************************************************************/
#define MRBC_NO_SCHEDULER  1

#define MRBC_OUT_OF_MEMORY() unreal_mrbc_out_of_memory()


/***** Typedefs *************************************************************/
/***** Global variables *****************************************************/
/***** Function prototypes **************************************************/
#ifdef __cplusplus
extern "C" {
#endif

void hal_init(void);

/* Implemented in Unreal */
void unreal_mrbc_out_of_memory(void);
int unreal_hal_write(int fd, const void *buf, int nbytes);
int unreal_hal_flush(int fd);


/***** Inline functions *****************************************************/
//================================================================
/*!@brief
  Write

  @param  fd    dummy, but 1.
  @param  buf   pointer of buffer.
  @param  nbytes        output byte length.
*/
inline static int hal_write(int fd, const void *buf, int nbytes)
{
  return unreal_hal_write(fd, buf, nbytes);
}


//================================================================
/*!@brief
  Flush write buffer

  @param  fd    dummy, but 1.
*/
inline static int hal_flush(int fd)
{
  return unreal_hal_flush(fd);
}


#ifdef __cplusplus
}
#endif
#endif // ifndef MRBC_HAL_H_
