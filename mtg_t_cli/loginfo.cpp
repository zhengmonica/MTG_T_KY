#include "mtg_t_cliApp.h"

wxString logInfo[MTG_LOG_COUNT]=
{
    _("转向后视..."),//0
    _("转向激光靶..."),//1
    _("停止激光..."),//2
    _("照准后视..."),//3
    _("测量后视..."),//4
    _("照准激光靶..."),//5
    _("测量激光靶位置..."),//6
    _("照准激光屏..."),//7
    _("测量激光角度..."),//8
    _("打开激光..."),//9
    _("全站仪初始化..."),//10
    _("激光靶姿态角初始化..."),//11
    _("激光屏初始化..."),//12
    _("转向吊篮..."),//13
    _("照准吊篮..."),//14
    _("测量吊篮..."),//15
    _("转向管环监测点..."),//16
    _("测量管环监测点..."),//17
    _("照准管环监测点..."),//18
    _("拼装..."),//19
    _("开始动作数"),//19

    _("转向后视成功！"),//20
    _("转向激光靶成功！"),//21
    _("停止激光成功！"),//22
    _("照准后视成功！"),//23
    _("测量后视成功！"),//24
    _("照准激光靶成功！"),//25
    _("测量激光靶位置成功！"),//26
    _("转向激光屏成功！"),//27
    _("测量激光角度成功！"),//28
    _("打开激光成功！"),//29
    _("全站仪初始化成功！"),//30
    _("激光靶角度初始化成功！"),//31
    _("激光靶激光屏初始化成功！"),//32
    _("转向吊篮成功！"),//33
    _("照准吊篮成功！"),//34
    _("测量吊篮成功！"),//34
    _("转向管环监测点成功！"),//34
    _("测量管环监测点成功！"),//34
    _("照准管环监测点成功！"),//34
    _("打开补偿器成功！"),//34
    _("关闭补偿器成功！"),//34
    _("测站设置成功！"),//34
    _("棱镜高设置成功！"),//34
    _("方位角设置成功！"),//34
    _("初始姿态测量完成！"),//34
    _("姿态测量完成！"),//34
    _("数据存储完成！"),//34
    _("目标初始化完成！"),//34
    _("吊篮测量完成！"),//34
    _("成功动作"),//19

    _("转向后视失败，请检查！"),//20
    _("转向激光靶失败，请检查！"),//21
    _("停止激光失败，请检查！"),//22
    _("照准后视失败，请检查！"),//23
    _("测量后视失败，请检查！"),//24
    _("照准激光靶失败，请检查！"),//25
    _("测量激光靶位置失败，请检查！"),//26
    _("转向激光屏失败，请检查！"),//27
    _("测量激光角度失败，请检查！"),//28
    _("打开激光失败，请检查！"),//29
    _("全站仪初始化失败，请检查！"),//30
    _("激光靶姿态角初始化失败，请检查！"),//31
    _("激光屏初始化失败，请检查！"),//32
    _("转向吊篮失败，请检查！"),//33
    _("照准吊篮失败，请检查！"),//34
    _("测量吊篮失败，请检查！"),//34
    _("转向管环监测点失败，请检查！"),//34
    _("测量管环监测点失败，请检查！"),//34
    _("照准管环监测点失败，请检查！"),//34
    _("打开补偿器失败，请检查！"),//34
    _("关闭补偿器失败，请检查！"),//34
    _("测站设置失败，请检查！"),//34
    _("棱镜高设置失败，请检查！"),//34
    _("方位角设置失败，请检查！"),//34
    _("零位测量失败，请检查！"),//34
    _("姿态测量失败！，请检查！"),//34
    _("数据存储失败，请检查！"),//34
    _("错误的激光靶位置，请检查！"),//34
    _("失败动作"),//19

    _("加密锁错误，请检查！"),//34
    _("电子补偿超限，请检查！"),//34
    _("错误"),//19

    _("测量终止！"),//34
    _("开始测量！"),//34
    _("正在测量中..."),//34
    _("硬件已初始化！"),//34
    _("电子补偿更新！"),//34
    _("电量更新！"),//34
    _("测量已停止！"),//34

    _("服务器连接成功！"),//34
    _("远程连接成功！"),//34
    _("服务器退出！"),//34
    _("远程退出！"),//34
    _("工程设置获取完成！"),//34
    _("关键区域获取完成！"),//34
    _("TBM设置获取完成！"),//34
    _("激光靶设置获取完成！"),//34
    _("激光屏参数获取完成！"),//34
    _("全站仪设置获取完成！"),//34
    _("管环设置获取完成！"),//34
    _("管块参数获取完成！"),//34
    _("初始姿态获取完成！"),//34
    _("系统设置获取完成！"),//34
    _("管环监测参数获取完成！"),//34
    _("用户获取完成！"),//34
    _("平曲线要素获取完成！"),//34
    _("竖曲线要素获取完成！"),//34
    _("水平平移获取完成！"),//34
    _("垂直平移获取完成！"),//34
    _("长短链获取完成！"),//34
    _("吊篮坐标获取完成！"),//34
    _("测站获取完成！"),//34
    _("远程已初始化完成！"),//34
    _("系统状态获取完成！"),//34
};

int DecodeLogString(int nLog,wxString& strLog)
{
    if(nLog<0 || nLog>MTG_LOG_COUNT) return 0;
    strLog=logInfo[nLog];
    return 1;
}

int DecodeLog(int nLog,wxString& strLog,int& colorLog)
{
    if(nLog<0 || nLog>MTG_LOG_COUNT) return 0;
    strLog=logInfo[nLog];
    ///日志类型
    if(nLog<=22)
    {
        colorLog=0;
    }
    else if(nLog<=46)
    {
        colorLog=1;
    }
    else if(nLog<=70)
    {
        colorLog=0;
    }
    else if(nLog<=76)
    {
        colorLog=0;
    }
    else
    {
        colorLog=0;
    }
    return 1;
}

wxString TPS_RETURN_CHS[GRC_COUNT]=
{
    _("执行成功"),                       ///GRC_OK,Function successfully completed.
    _("未知错误，结果不可用"),           ///GRC_UNDEFINED,Unknown error, result unspecified.
    _("无效参数，结果不可用"),           ///GRC_IVPARAM,Invalid parameter detected. Result unspecified.
    _("无效参数，结果不可用"),           ///GRC_IVRESULT,Invalid result.
    _("致命错误"),                       ///GRC_FATAL,Fatal error.
    _("未执行"),                         ///GRC_NOT_IMPL,Not implemented yet.
    _("执行超时"),                       ///GRC_TIME_OUT,Function execution timed out. Result unspecified.
    _("参数不完整"),                     ///GRC_SET_INCOMPL,Parameter setup for subsystem is incomplete.
    _("程序执行中断"),                   ///GRC_ABORT,Function execution has been aborted.
    _("致命错误，内存不足"),             ///GRC_NOMEMORY,Fatal error - not enough memory.
    _("子系统未初始化"),                 ///GRC_NOTINIT,Fatal error - subsystem not initialized.
    _("子系统关闭"),                     ///GRC_SHUT_DOWN,Subsystem is down.
    _("系统忙"),                         ///GRC_SYSBUSY,System busy/already in use of another process.Cannot execute function.
    _("致命错误，硬件故障"),             ///GRC_HWFAILURE,Fatal error - hardware failure.
    _("程序执行中断（SHIFT ESC）"),      ///GRC_ABORT_APPL,Execution of application has been aborted(SHIFT-ESC).
    _("程序执行中断（低电量）"),         ///GRC_LOW_POWER,Operation aborted - insufficient power supply level.
    _("无效的版本文件"),                 ///GRC_IVVERSION,Invalid version of file, ...
    _("电池电量空"),                     ///GRC_BATT_EMPTY,Battery empty
    _("指令失败"),                       ///GRC_NO_EVENT,no event pending.
    _("温度过高"),                       ///GRC_OUT_OF_TEM,Pout of temperature range
    _("超出补偿范围"),                   ///GRC_INSTRUMENT_TILT,instrument tilting out of range
    _("通讯错误"),                       ///GRC_COM_SETTING,communication error
    _("无操作"),                         ///GRC_NO_ACTION,GRC_TYPE Input 'do no action'
    _("进入休眠模式"),                   ///GRC_SLEEP_MODE,Instr. run into the sleep mode
    _("程序未执行完成"),                 ///GRC_NOTOK,Function not successfully completed.
    _("返回值无效"),                     ///GRC_NA,Not available
    _("数据错误"),                       ///GRC_OVERFLOW,Overflow error
    _("系统或子系统停止工作"),           ///GRC_STOPPED,System or subsystem has been stopped

    _("角度和电子补偿无效"),             ///GRC_ANG_ERROR,Angles and Inclinations not valid
    _("电子补偿无效"),                   ///GRC_ANG_INCL_ERROR,inclinations not valid
    _("角度精度不满足要求"),             ///GRC_ANG_BAD_ACC,value accuracies not reached
    _("角度精度不满足要求"),             ///GRC_ANG_BAD_ANGLE_ACC,angle-accuracies not reached
    _("电子补偿精度不满足要求"),         ///GRC_ANG_BAD_INCLIN_ACC,inclination accuracies not reached
    _("不可写如数据"),                   ///GRC_ANG_WRITE_PROTECTED,no write access allowed
    _("值超出范围"),                     ///GRC_ANG_OUT_OF_RANGE,value out of range
    _("程序执行因干扰中断"),             ///GRC_ANG_IR_OCCURED,function aborted due to interrupt
    _("电子补偿时仪器水平转动"),         ///GRC_ANG_HZ_MOVED,hz moved during incline measurement
    _("系统错误"),                       ///GRC_ANG_OS_ERROR,troubles with operation system
    _("参数错误"),                       ///GRC_ANG_DATA_ERROR,overflow at parameter values
    _("信号弱"),                         ///GRC_ANG_PEAK_CNT_UFL,too less peaks
    _("超时"),                           ///GRC_ANG_TIME_OUT,reading timeout
    _("角度精度不满足要求"),             ///GRC_ANG_TOO_MANY_EXPOS,too many exposures wanted
    _("高度超出范围"),                   ///GRC_ANG_PIX_CTRL_ERR,picture height out of range
    _("曝光过度"),                       ///GRC_ANG_MAX_POS_SKIP,positive exposure dynamic overflow
    _("曝光不足"),                       ///GRC_ANG_MAX_NEG_SKIP,negative exposure dynamic overflow
    _("曝光超时"),                       ///GRC_ANG_EXP_LIMIT,exposure time overflow
    _("picture underexposured"),         ///GRC_ANG_UNDER_EXPOSURE,picture underexposured
    _("picture overexposured"),          ///GRC_ANG_OVER_EXPOSURE,picture overexposured
    _("干扰严重"),                       ///GRC_ANG_TMANY_PEAKS,too many peaks detected
    _("信号弱"),                         ///GRC_ANG_TLESS_PEAKS,too less peaks detected
    _("信号峰过窄"),                     ///GRC_ANG_PEAK_TOO_SLIM,peak too slim
    _("信号峰过宽"),                     ///GRC_ANG_PEAK_TOO_WIDE,peak to wide
    _("错误信号"),                       ///GRC_ANG_BAD_PEAKDIFF,bad peak difference
    _("太少的峰值"),                     ///GRC_ANG_UNDER_EXP_PICT,too less peak amplitude
    _("不均匀的峰值振幅"),               ///GRC_ANG_PEAKS_INHOMOGEN,inhomogeneous peak amplitudes
    _("不能解码"),                       ///GRC_ANG_NO_DECOD_POSS,no peak decoding possible
    _("峰值解码不稳定"),                 ///GRC_ANG_UNSTABLE_DECOD,peak decoding not stable
    _("有效峰值太少"),                   ///GRC_ANG_TLESS_FPEAKS,too less valid finepeaks
    _("水平补偿超时"),                   ///GRC_ANG_INCL_OLD_PLANE,inclination plane out of time range
    _("水平补不可用"),                   ///GRC_ANG_INCL_NO_PLANE,inclination no plane available
    _("5kHz and or 2.5kHz错误"),         ///GRC_ANG_FAST_ANG_ERR,errors in 5kHz and or 2.5kHz angle
    _("5kHz错误"),                       ///GRC_ANG_FAST_ANG_ERR_5,errors in 5kHz angle
    _("2.5kHz错误"),                     ///GRC_ANG_FAST_ANG_ERR_25,
    _("检测到错误的LVDS传输"),           ///GRC_ANG_TRANS_ERR,LVDS transfer error detected
    _("LVDS传输错误位于5kHz"),           ///GRC_ANG_TRANS_ERR_5,LVDS transfer error detected in 5kHz mode
    _("LVDS传输错误位于2.5kHz"),         ///GRC_ANG_TRANS_ERR_25,LVDS transfer error detected in 2.5kHz mode

    _("ATR自动照准系统未准备完成"),      ///GRC_ATA_NOT_READY,ATR-System is not ready
    _("结果还未可用"),                   ///GRC_ATA_NO_RESULT,Result isn't available yet
    _("检测到过个目标"),                 ///GRC_ATA_SEVERAL_TARGETS,Several Targets detected
    _("棱镜异常，不能完成照准分析"),     ///GRC_ATA_BIG_SPOT,Spot is too big for analyse.
    _("背景太亮"),                       ///GRC_ATA_BACKGROUND,Background is too bright.
    _("未检测到棱镜"),                   ///GRC_ATA_NO_TARGETS,No targets detected.
    _("照准精度太差，不能满足要求"),     ///GRC_ATA_NOT_ACCURAT,Accuracy worse than asked for.
    _("棱镜影像位于传感器边缘"),         ///GRC_ATA_SPOT_ON_EDGE,Spot is on the edge of the sensing area.
    _("棱镜边缘不规则"),                 ///GRC_ATA_BLOOMING,Blooming or spot on edge detected
    _("ATR为不连续模式"),                ///GRC_ATA_NOT_BUSY,ATR isn't in a continuous mode
    _("环境光干扰"),                     ///GRC_ATA_STRANGE_LIGHT,Not the spot of the own target illuminator
    _("ATR传感器通信异常"),              ///GRC_ATA_V24_FAIL,Communication error to sensor (ATR).
    _("目标反射信号无法识别"),           ///GRC_ATA_DECODE_ERROR,
    _("水平方向检测不到信号"),           ///GRC_ATA_HZ_FAIL,No Spot detected in Hz-direction.
    _("垂直方向检测不到信号"),           ///GRC_ATA_V_FAIL,No Spot detected in V-direction.
    _("水平方向受光干扰"),               ///GRC_ATA_HZ_STRANGE_L,Strange light in Hz-direction.
    _("垂直方向受光干扰"),               ///GRC_ATA_V_STRANGE_L,Strange light in V-direction.
    _("多ata_sldr_opentransfer"),        ///GRC_ATA_SLDR_TRANSFER_PENDING,On multiple ATA_SLDR_OpenTransfer.
    _("没有ata_sldr_opentransfer发生"),  ///GRC_ATA_SLDR_TRANSFER_ILLEGAL,No ATA_SLDR_OpenTransfer happened.
    _("数据格式错误"),                   ///GRC_ATA_SLDR_DATA_ERROR,Unexpected data format received.
    _("数据校验错误"),                   ///GRC_ATA_SLDR_CHK_SUM_ERROR,Checksum error in transmitted data.
    _("内存错误"),                       ///GRC_ATA_SLDR_ADDRESS_ERROR,Address out of valid range.
    _("固件错误"),                       ///GRC_ATA_SLDR_INV_LOADFILE,Firmware file has invalid format.
    _("当前固件不支持上传"),             ///GRC_ATA_SLDR_UNSUPPORTED,Current (loaded) firmware doesn't support upload.
    _("PS-SYSTEM未准备好"),              ///GRC_ATA_PS_NOT_READY,PS-System is not ready.
    _("ATR错误"),                        ///GRC_ATA_ATR_SYSTEM_ERR,ATR system error

    _("测距头致命错误"),              ///GRC_EDM_SYSTEM_ERR,Fatal EDM sensor error. See for the exactreason the original EDM sensor error number.In the most cases a service problem.
    _("无效的命令"),                  ///GRC_EDM_INVALID_COMMAND,Invalid command or unknown command, see command syntax.
    _("转角错误"),                    ///GRC_EDM_BOOM_ERR,Boomerang error.
    _("测距信号弱"),                  ///GRC_EDM_SIGN_LOW_ERR,Received signal to low, prism to far away, or natural barrier, bad environment, etc.
    _("测距头致命错误"),              ///GRC_EDM_DIL_ERR,obsolete
    _("环境光干扰"),                  ///GRC_EDM_SIGN_HIGH_ERR,Received signal to strong, prism to near,stranger light effect.
    _("测距超时"),                    ///GRC_EDM_TIMEOUT,Timeout, measuring time exceeded (signal too weak, beam interrupted,..)
    _("目标震动或干扰"),              ///GRC_EDM_FLUKT_ERR,to much turbulences or distractions
    _("震动过滤器错误"),              ///GRC_EDM_FMOT_ERR,filter motor defective
    _("EGL或DL没有安装"),             ///GRC_EDM_DEV_NOT_INSTALLED,Device like EGL, DL is not installed.
    _("搜索无效"),                    ///GRC_EDM_NOT_FOUND,Search result invalid. For the exact explanation,see in the description of the called function.
    _("EDM通讯正常，ECM报告异常"),    ///GRC_EDM_ERROR_RECEIVED,Communication ok, but an error reported from the EDM sensor.
    _("无服务授权"),                  ///GRC_EDM_MISSING_SRVPWD,No service password is set.
    _("EDM通讯正常，收到意外返回"),   ///GRC_EDM_INVALID_ANSWER,Communication ok, but an unexpected answer received.
    _("数据发送错误"),                ///GRC_EDM_SEND_ERR,Data send error, sending buffer is full.
    _("数据接收错误"),                ///GRC_EDM_RECEIVE_ERR,Data receive error, like parity buffer overflow.
    _("EDM子系统错误"),               ///GRC_EDM_INTERNAL_ERR,Internal EDM subsystem error.
    _("EDM忙"),                       ///GRC_EDM_BUSY,Sensor is working already, abort current measuring first
    _("没有测量动作"),                ///GRC_EDM_NO_MEASACTIVITY,No measurement activity started.
    _("接收数据错误"),                ///GRC_EDM_CHKSUM_ERR,Calculated checksum, resp. received data wrong (only in binary communication mode possible).
    _("开机或关机导致EDM异常"),       ///GRC_EDM_INIT_OR_STOP_ERR,During start up or shut down phase an error occured. It is saved in the DEL buffer.
    _("激光无效"),                    ///GRC_EDM_SRL_NOT_AVAILABLE,Red laser not available on this sensor HW.
    _("测量中断"),                    ///GRC_EDM_MEAS_ABORTED,Measurement will be aborted (will be used for the laser security)
    _("任务冲突"),                    ///GRC_EDM_SLDR_TRANSFER_PENDING,Multiple Open Transfer calls.
    _("发送数据异常"),                ///GRC_EDM_SLDR_TRANSFER_ILLEGAL,No open transfer happened.
    _("接收数据格式异常"),            ///GRC_EDM_SLDR_DATA_ERROR,Unexpected data format received.
    _("发送数据时异常"),              ///GRC_EDM_SLDR_CHK_SUM_ERROR,Checksum error in transmitted data.
    _("内存错误"),                    ///GRC_EDM_SLDR_ADDR_ERROR,Address out of valid range.
    _("固件文件错误"),                ///GRC_EDM_SLDR_INV_LOADFILE,Firmware file has invalid format.
    _("固件不支持上传"),              ///GRC_EDM_SLDR_UNSUPPORTED,Current (loaded) firmware doesn't support upload.
    _("EDM未知错误"),                 ///GRC_EDM_UNKNOW_ERR,Undocumented error from the EDM sensor,should not occur.
    _("测量距离超出范围"),            ///GRC_EDM_DISTRANGE_ERR,Out of distance range (dist too small or large)
    _("信噪比太小"),                  ///GRC_EDM_SIGNTONOISE_ERR,Signal to noise ratio too small
    _("信噪比太大"),                  ///GRC_EDM_NOISEHIGH_ERR,Noise to high
    _("服务未授权"),                  ///GRC_EDM_PWD_NOTSET,Password is not set
    _("设置超时"),                    ///GRC_EDM_ACTION_NO_MORE_VALID,Elapsed time between prepare und start fast measurement for ATR to long
    _("多个目标"),                    ///GRC_EDM_MULTRG_ERR,Possibly more than one target (also a sensor error)
    _("EEPROM常量无"),                ///GRC_EDM_MISSING_EE_CONSTS,eeprom consts are missing
    _("无法精确测量"),                ///GRC_EDM_NOPRECISE,No precise measurement possible
    _("测量距离太远"),                ///GRC_EDM_MEAS_DIST_NOT_ALLOWED,Measured distance is to big (not allowed)

    _("测量值未进行完全修正"),                ///GRC_TMC_NO_FULL_CORRECTION,Warning: measurement without full correction
    _("测量结果精度不保证"),                  ///GRC_TMC_ACCURACY_GUARANTEE,Info: accuracy can not be guarantee
    _("仅测角有效"),                          ///GRC_TMC_ANGLE_OK,Warning: only angle measurement valid
    _("仅测角有效且未进行完全修正"),          ///GRC_TMC_ANGLE_NOT_FULL_CORR,Warning: only angle measurement valid but without full correction
    _("仅测角有效且精度不保证"),              ///GRC_TMC_ANGLE_NO_ACC_GUARANTY,Info: only angle measurement valid but accuracy can not be guarantee
    _("未进行测角"),                          ///GRC_TMC_ANGLE_ERROR,Error: no angle measurement
    _("PPM 或 MM 或 EDM 设置错误"),           ///GRC_TMC_DIST_PPM,Error: wrong setting of PPM or MM on EDM
    _("未进行测距"),                          ///GRC_TMC_DIST_ERROR,Error: distance measurement not done (no aim,etc.)
    _("系统忙，未执行测量任务"),              ///GRC_TMC_BUSY,Error: system is busy (no measurement done)
    _("无测距信号"),                          ///GRC_TMC_SIGNAL_ERROR,Error: no signal on EDM (only in signal mode)
    _("电子补偿超出范围"),                    ///GRC_OLD_PLANE,Warning: inclination out of time range
    _("测量值未进行倾斜修正"),                ///GRC_NO_PLANE,Warning: measurement without planeinclination correction
    _("测量值未进行倾斜修正"),                ///GRC_INC_ERROR,Warning: measurement without sensor inclination correction
    _("电子补偿值精度不保证"),                ///GRC_INCLINE_ACC,Info : inclination accuracy can not beguaranteed

    _("马达未准备完成"),                      ///GRC_MOT_UNREADY,motorization is not ready
    _("马达进行其他任务"),                    ///GRC_MOT_BUSY,motorization is handling another task
    _("马达模式异常"),                        ///GRC_MOT_NOT_OCONST,motorization is not in velocity mode
    _("马达模式异常或马达忙"),                ///GRC_MOT_NOT_CONFIG,motorization is in the wrong mode or busy
    _("马达模式异常"),                        ///GRC_MOT_NOT_POSIT,motorization is not in posit mode
    _("马达模式异常"),                        ///GRC_MOT_NOT_SERVICE,motorization is not in service mode
    _("马达未收到指令"),                      ///GRC_MOT_NOT_BUSY,motorization is handling no task
    _("马达未处于跟踪模式"),                  ///GRC_MOT_NOT_LOCK,motorization is not in tracking mode
    _("马达模式异常"),                        ///GRC_MOT_NOT_SPIRAL,motorization is not in spiral mode
    _("垂直度盘异常"),                        ///GRC_MOT_V_ENCODER,vertical encoder/motor error
    _("水平度盘异常"),                        ///GRC_MOT_HZ_ENCODER,horizontal encoder/motor error
    _("水平和垂直度盘异常"),                  ///GRC_MOT_HZ_V_ENCODER,horizontal and vertical encoder/motor error

    _("启动扩展运行"),                        ///GRC_COM_ERO,Initiate Extended Runtime Operation (ERO).
    _("客户端不能解析参数"),                  ///GRC_COM_CANT_ENCODE,Cannot encode arguments in client.
    _("客户端不能解析数据"),                  ///GRC_COM_CANT_DECODE,Cannot decode results in client.
    _("发生数据硬件错误"),                    ///GRC_COM_CANT_SEND,Hardware error while sending.
    _("接收数据硬件错误"),                    ///GRC_COM_CANT_RECV,Hardware error while receiving.
    _("请求超时"),                            ///GRC_COM_TIMEDOUT,Request timed out.
    _("数据包格式错误"),                      ///GRC_COM_WRONG_FORMAT,Packet format error.
    _("客户端与服务端版本不匹配"),            ///GRC_COM_VER_MISMATCH,Version mismatch between client and server.
    _("服务器不能解码参数"),                  ///GRC_COM_CANT_DECODE_REQ,Cannot decode arguments in server.
    _("未知命令"),                            ///GRC_COM_PROC_UNAVAIL,Unknown RPC, procedure ID invalid.
    _("服务器不能解码"),                      ///GRC_COM_CANT_ENCODE_REP,Cannot encode results in server.
    _("未知的系统错误"),                      ///GRC_COM_SYSTEM_ERR,Unspecified generic system error.
    _("未知错误"),                            ///GRC_COM_FAILED,Unspecified error.
    _("二进制协议无效"),                      ///GRC_COM_NO_BINARY,Binary protocol not available.
    _("请求中断"),                            ///GRC_COM_INTR,Call interrupted.
    _("协议为8位编码"),                       ///GRC_COM_REQUIRES_8DBITS,Protocol needs 8bit encoded characters.
    _("传输ID匹配错误"),                      ///GRC_COM_TR_ID_MISMATCH,TRANSACTIONS ID mismatch error.
    _("协议不可识别"),                        ///GRC_COM_NOT_GEOCOM,Protocol not recognizable.
    _("无效端口地址"),                        ///GRC_COM_UNKNOWN_PORT,(WIN) Invalid port address.
    _("重组终止"),                            ///GRC_COM_ERO_END,ERO is terminating.
    _("内存溢出"),                            ///GRC_COM_OVERRUN,Internal error: data buffer overflow.
    _("服务端接受到无效的校验"),              ///GRC_COM_SRVR_RX_CHECKSUM_ERRR,Invalid checksum on server side received.
    _("客户端接收到无效的校验"),              ///GRC_COM_CLNT_RX_CHECKSUM_ERRR,Invalid checksum on client side received.
    _("端口无效"),                            ///GRC_COM_PORT_NOT_AVAILABLE,(WIN) Port not available.
    _("端口被占用"),                          ///GRC_COM_PORT_NOT_OPEN,(WIN) Port not opened.
    _("无TPS设备"),                           ///GRC_COM_NO_PARTNER,(WIN) Unable to find TPS.
    _("不能执行扩展操作"),                    ///GRC_COM_ERO_NOT_STARTED,Extended Runtime Operation could not be started.
    _("Att to send cons reqs"),               ///GRC_COM_CONS_REQ,Att to send cons reqs
    _("TPS进入休眠模式"),                     ///GRC_COM_SRVR_IS_SLEEPING,TPS has gone to sleep. Wait and try again.
    _("TPS已关机"),                           ///GRC_COM_SRVR_IS_OFF,TPS has shut down. Wait and try again.
    _("ASCII协议无效"),                       ///GRC_COM_NO_CHECKSUM,No checksum in ASCII protocol available.AUT 8704

    _("未定位"),                                             ///GRC_AUT_TIMEOUT,Position not reached
    _("定位无效"),                                           ///GRC_AUT_DETENT_ERROR,Positioning not possible due to mounted EDM
    _("测角错误"),                                           ///GRC_AUT_ANGLE_ERROR,Angle measurement error
    _("马达错误"),                                           ///GRC_AUT_MOTOR_ERROR,Motorisation error
    _("未精确定位"),                                         ///GRC_AUT_INCACC,Position not exactly reached
    _("设备错误"),                                           ///GRC_AUT_DEV_ERROR,Deviation measurement error
    _("无目标"),                                             ///GRC_AUT_NO_TARGET,No target detected
    _("多个目标"),                                           ///GRC_AUT_MULTIPLE_TARGETS,Multiple target detected
    _("环境条件差"),                                         ///GRC_AUT_BAD_ENVIRONMENT,Bad environment conditions
    _("捕获目标错误"),                                       ///GRC_AUT_DETECTOR_ERROR,Error in target acquisition
    _("不能捕获目标"),                                       ///GRC_AUT_NOT_ENABLED,Target acquisition not enabled
    _("自动照准计算失败"),                                   ///GRC_AUT_CALACC,ATR-Calibration failed
    _("不能精确捕获目标"),                                   ///GRC_AUT_ACCURACY,Target position not exactly reached
    _("测距开始"),                                           ///GRC_AUT_DIST_STARTED,Info: dist. measurement has been started
    _("外置供电电压过高"),                                   ///GRC_AUT_SUPPLY_TOO_HIGH,external Supply voltage is too high
    _("外置供电电压过低"),                                   ///GRC_AUT_SUPPLY_TOO_LOW,int. or ext. Supply voltage is too low
    _("未设置搜索区域"),                                     ///GRC_AUT_NO_WORKING_AREA,working area not set
    _("power search data array is filled"),                  ///GRC_AUT_ARRAY_FULL,power search data array is filled
    _("无效数据"),                                           ///GRC_AUT_NO_DATA,no data available
    _("motion cannot be executed because of sidecove"),      ///GRC_AUT_SIDECOVER_ERR,motion cannot be executed because of sidecove
    _("angle requested for time not in collection"),         ///GRC_AUT_OUT_OF_SYNC,angle requested for time not in collection (probably telescope out of sync)
    _("锁定模式不可用"),                                     ///GRC_AUT_NO_LOCK, lock mode not allowed

    _("KDM设备不可用"),                                 ///GRC_KDM_NOT_AVAILABLE,KDM device is not available.
    _("文件操作错误"),                                  ///GRC_FTR_FILEACCESS,File access error
    _("数据块错误"),                                    ///GRC_FTR_WRONGFILEBLOCKNUMBER,block number was not the expected one
    _("存储空间不足"),                                  ///GRC_FTR_NOTENOUGHSPACE,not enough space on device to proceed uploading
    _("重命名失败"),                                    ///GRC_FTR_INVALIDINPUT,Rename of file failed.
    _("输入参数无效"),                                  ///GRC_FTR_MISSINGSETUP,invalid parameter as input

    _("相机系统准备未完成"),                        ///GRC_CAM_NOT_READY,CAM-System is not ready
    _("相机未初始化"),                              ///GRC_CAM_NOT_INIT,Camera is not initialised
    _("图像不可用"),                                ///GRC_CAM_IMG_NOT_AVAILABLE,Image from the camera is not available
    _("存储图像错误"),                              ///GRC_CAM_IMAGE_SAVING_ERROR,Error while saving image
    _("图像位深错误"),                              ///GRC_CAM_BIT_DEPTH_ERROR,Bit depth of the image is wrong
    _("内存不足"),                                  ///GRC_CAM_OUT_OF_MEMORY,There is no memory available
    _("光斑无效"),                                  ///GRC_CAM_SPOT_NOT_AVAIL,Required spot is not available
    _("无光斑数据"),                                ///GRC_CAM_NO_SPOTS_INLIST,Spot list is empty
    _("图像无光斑"),                                ///GRC_CAM_NO_TARGET,There are no spots in image
    _("无有效光斑"),                                ///GRC_CAM_TARGET_NOT_FOUND,Required target is not found
    _("校准数据丢失"),                              ///GRC_CAM_NO_CALIB_INPUT_DATA,Calibration input data is missing
    _("测量精度不满足要求"),                        ///GRC_CAM_MEAS_NOT_ACCURATE,Measurement is not accurate
    _("相机镜头污染"),                              ///GRC_CAM_DIRTY,Camera cleanness check failed, camera is dirty
};

int DecodeTpsret(int grc,wxString& ret)
{
    if(grc<0 || grc>GRC_COUNT) return 0;
    ret=TPS_RETURN_CHS[grc];
    return 1;
}
