demo:
画两个圆，如果移动其中一个圆，它对应的线就跟着移动。
遇到的问题总结：
1.setFlag 的问题，由于设置flag错误，出现焦点没有移除，没有点击空白处的时候，移动一个圆，另一个也跟着移动。
2.boundRect()函数，如果返回值 QReCt()返回的范围小的话，就会看不到图像的绘制。
3.设置prepareGeometryChange以后，boundRect()的返回值变化的时候，会自动调用 painter()函数进行更新。
