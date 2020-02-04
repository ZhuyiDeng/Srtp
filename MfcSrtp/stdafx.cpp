
// stdafx.cpp : 只包括标准包含文件的源文件
// MfcSrtp.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

CString filePath;
CString skPath;
CString mskPath;
CString skName;//文件名称
float portion;
int width;
int height;
static int count;//色卡文件中的行数，即颜色数量
int i;//色卡文件中的行数标记
CString text;//创建对照表中编辑框内容