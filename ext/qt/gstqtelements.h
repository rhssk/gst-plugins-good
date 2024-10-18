/*
 * Copyright (C) 2020 Huawei Technologies Co., Ltd.
 *   @Author: Julian Bouzas <julian.bouzas@collabora.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef __GST_QT_ELEMENTS_H__
#define __GST_QT_ELEMENTS_H__

#include <gst/gst.h>

G_BEGIN_DECLS

void qt5_element_init (GstPlugin * plugin);

#ifndef GST_ELEMENT_REGISTER_DECLARE
#define GST_ELEMENT_REGISTER_DECLARE(element) \
G_BEGIN_DECLS \
gboolean G_PASTE(gst_element_register_, element) (GstPlugin * plugin); \
G_END_DECLS
#endif

#ifndef GST_ELEMENT_REGISTER
#define GST_ELEMENT_REGISTER(element, plugin) G_PASTE(gst_element_register_, element) (plugin)
#endif

#ifndef _GST_ELEMENT_REGISTER_DEFINE_BEGIN
#define _GST_ELEMENT_REGISTER_DEFINE_BEGIN(element) \
G_BEGIN_DECLS \
gboolean G_PASTE (gst_element_register_, element) (GstPlugin * plugin) \
{ \
  {
#endif

#ifndef _GST_ELEMENT_REGISTER_DEFINE_END
#define _GST_ELEMENT_REGISTER_DEFINE_END(element_name, rank, type) \
  } \
  return gst_element_register (plugin, element_name, rank, type); \
} \
G_END_DECLS
#endif

#ifndef GST_ELEMENT_REGISTER_DEFINE_WITH_CODE
#define GST_ELEMENT_REGISTER_DEFINE_WITH_CODE(e, e_n, r, t, _c_) _GST_ELEMENT_REGISTER_DEFINE_BEGIN(e) {_c_;} _GST_ELEMENT_REGISTER_DEFINE_END(e_n, r, t)
#endif

GST_ELEMENT_REGISTER_DECLARE (qmlglsink);
GST_ELEMENT_REGISTER_DECLARE (qmlglsrc);
GST_ELEMENT_REGISTER_DECLARE (qmlgloverlay);

G_END_DECLS

#endif /* __GST_QT_ELEMENTS_H__ */
