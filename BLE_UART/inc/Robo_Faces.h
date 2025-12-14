/**
 * @file Robo_Faces.c
 *
 * @brief Byte arrays (84 x 48) of the images used for the robots face.
 *
 *  Changed images into byte arrays using: https://javl.github.io/image2cpp/
 *
 *
 * @author Evelyn Dominguez
 *
 */
#ifndef INC_ROBO_FACES_H_
#define INC_ROBO_FACES_H_

/*
 *  @breif Byte array of Dom Toretto from Fast and Furious
 */
extern const unsigned char DomToretto[];

/*
 * @breif Ovo's default face
 */
extern const unsigned char Ovo_face[];
/*
 * @brief Ovo's face when moving backward
 */
extern const unsigned char Looking_Back[];

/*
 * @brief Ovo's face moving forward
 */
extern const unsigned char Forward_Face[];

/*
 * @brief Ovo's face when turning left
 */
extern const unsigned char Left_Face[];
/*
 * @brief Ovo's face when turning right
 */
extern const unsigned char Right_Face[];


#endif /* INC_ROBO_FACES_H_ */
