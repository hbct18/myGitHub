# 包含基本的子系统参数定义
include $(OB_REL)/etc/NGbasedefine.mk

# 目标名称，不用带 lib 的前缀或者 D.so 的后缀，最后生成的文件名是 lib$(DEST)_mgr$(DLLTAIL)【必须修改】
DEST = mdb_query

# 目标的类型，必须是 MGR【不能修改】
DEST_TYPE = BIN

# 编译目标程序需要的源代码文件，可以带路径（但必须是绝对路径）【必须修改】
DEST_SOURCES = 	mdb_query.cpp \
				mdbServer_logic.cpp \
				mdbServer_query.cpp
				
# 目标的头文件安装路径，最终目录将是 $OB_REL/include/$(SUBSYSTEM)/$(HEADER_PATH)/ 【可选】
# HEADER_PATH = 

# 需要安装的头文件，文件名需带路径【可选】
# HEADERS =

# 用户定义的 include 路径，即除了 public 外的其它 include 路径【可选】		
USER_INC_PATH = $(OB_REL)/include/util/mdb/ \
				$(OB_REL)/include/public \


# 需要连接的其它库文件，应使用 $(BUILDTYPE) 作为后缀【可选】
USER_LIBRARIES = cdk_foundation$(BUILDTYPE) \
				public_sal$(BUILDTYPE) \
				public_xc$(BUILDTYPE) \
				public_sdl_basic$(BUILDTYPE) \
				public_config$(BUILDTYPE) \
				mdb_in_base$(BUILDTYPE) \
				mdbqueryMapreduce$(BUILDTYPE) \
				boost_thread \
				salroutedep$(BUILDTYPE)\
				
#########################################################
# 包含基本的 Makefile 规则文件
include $(OB_REL)/etc/NGCmake
