/**
 *  @file        raw_quic_api.h
 *  @brief       RawQuic api�����ļ�.
 *  @author      sonysuqin
 *  @copyright   sonysuqin
 *  @version     1.0.1
 */

#ifndef NET_QUIC_RAW_QUIC_RAW_QUIC_API_H_
#define NET_QUIC_RAW_QUIC_RAW_QUIC_API_H_

#include "raw_quic_define.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  @brief  ����һ��RawQuic���.
 *  @param  callback        �첽�ص�.
 *  @param  opaque          �ϲ㴫�ݵĲ��������ڻص�����Ϊ�����ش�.
 *  @param  verify          �Ƿ�У��֤��.
 *  @return RawQuic���.
 */
RAW_QUIC_API RawQuicHandle RAW_QUIC_CALL RawQuicOpen(RawQuicCallbacks callback,
                                                     void* opaque,
                                                     bool verify);

/**
 *  @brief  �ر�һ��RawQuic���.
 *  @param  handle          RawQuic���.
 *  @return ������.
 */
RAW_QUIC_API int32_t RAW_QUIC_CALL RawQuicClose(RawQuicHandle handle);

/**
 *  @brief  ʹ��RawQuic�������һ������.
 *  @param  handle          RawQuic���.
 *  @param  host            �����������ע��QUIC������ܣ����Ա�����������֤��.
 *  @param  port            ����˶˿�.
 *  @param  port            �����·��.
 *  @param  timeout         ��ʱʱ�䣬ms.
 *  @note   timeout��0ʱ��Ϊͬ��������������ֱ�����ӳɹ���ʧ�ܡ����߳�ʱ��
 *          ��timeoutΪ0ʱ��Ϊ�첽������connect_callback�����ص�.
 *  @return ������.
 */
RAW_QUIC_API int32_t RAW_QUIC_CALL RawQuicConnect(RawQuicHandle handle,
                                                  const char* host,
                                                  uint16_t port,
                                                  const char* path,
                                                  int32_t timeout);

/**
 *  @brief  ʹ��RawQuic�������һ������.
 *  @param  handle          RawQuic���.
 *  @param  data            ���ݻ����ַ.
 *  @param  size            ���ݳ���.
 *  @note   ֻ�Ƿŵ����ͻ�����.
 *  @return ���͵��ֽ������ߴ�����.
 */
RAW_QUIC_API int32_t RAW_QUIC_CALL RawQuicSend(RawQuicHandle handle,
                                               uint8_t* data,
                                               uint32_t size);

/**
 *  @brief  ʹ��RawQuic�������һ������.
 *  @param  handle          RawQuic���.
 *  @param  data            ���ݻ����ַ.
 *  @param  size            ���ݻ��泤��.
 *  @param  timeout         ��ʱʱ�䣬ms.
 *  @note   timeout��0ʱ�����ȴ�ֱ�������ݡ�ʧ�ܡ����߳�ʱ,
 *          timeoutΪ0ʱ��ֻ�ǳ��Լ����ջ������Ƿ������ݣ�
 *          ���򷵻����ݣ����򷵻�EAGAIN. can_read_callback
 *          �ص�����֪ͨ�����ݿɶ�(��Ե����).
 *  @return ���յ��ֽ������ߴ�����.
 */
RAW_QUIC_API int32_t RAW_QUIC_CALL RawQuicRecv(RawQuicHandle handle,
                                               uint8_t* data,
                                               uint32_t size,
                                               int32_t timeout);


/**
 *  @brief  ��ȡ���ջ����������ݳ���.
 *  @param  handle          RawQuic���.
 *  @return ���ջ����������ݳ���.
 */
RAW_QUIC_API int32_t RAW_QUIC_CALL RawQuicGetRecvBufferDataSize(RawQuicHandle handle);

/**
 *  @brief  ���÷��ͻ�������С.
 *  @param  handle          RawQuic���.
 *  @param  size            ��������С.
 */
RAW_QUIC_API void RawQuicSetSendBufferSize(RawQuicHandle handle, uint32_t size);

/**
 *  @brief  ��ȡ���ͻ������Ĵ�С.
 *  @param  handle          RawQuic���.
 *  @return ���ͻ������Ĵ�С.
 */
RAW_QUIC_API uint32_t RAW_QUIC_CALL RawQuicGetSendBufferSize(RawQuicHandle handle);

#ifdef __cplusplus
}
#endif

#endif  // NET_QUIC_RAW_QUIC_RAW_QUIC_API_H_
